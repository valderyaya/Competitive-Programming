//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

const int z=2e5+5, inf = 1e9+2;
int seg[z<<6],rt[z],lc[z<<6],rc[z<<6],n,m,cnt,lst;
void mdf(int l,int r,int x,int v,int &o,int pre){
    o=++cnt;
    lc[o]=lc[pre],rc[o]=rc[pre],seg[o]=seg[pre]^v;
    if(l==r) return;
    int mid=l+(r-l)/2;
    if(x<=mid) mdf(l,mid,x,v,lc[o],lc[pre]);
    else mdf(mid+1,r,x,v,rc[o],rc[pre]);
}
int qry(int l, int r, int L, int R){
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(seg[lc[R]]^seg[lc[L]]) return qry(l,mid,lc[L],lc[R]);
    return qry(mid+1,r,rc[L],rc[R]);
}
unordered_map<int,int> mp;
signed main(){StarBurstStream
    mt19937 rand(time(0));
    cin>>n;
    for(int x,i=1;i<=n;++i){
        cin>>x;
        if(!mp[x]) mp[x]=rand() % inf + 1;
        mdf(0,inf,x,mp[x],rt[i],rt[i-1]);
    }
    cin>>m;
    for(int l,r;m--;){
        cin>>l>>r;
        l^=lst, r^=lst;
        lst = qry(0,inf,rt[l-1],rt[r]);
        if(lst == inf) lst = 0;
        cout<<lst<<"\n";
    }
}
