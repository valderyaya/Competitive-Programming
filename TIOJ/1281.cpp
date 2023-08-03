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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

const ull base=347;
string s;
int n;
ull h[100001],p[100001];
ull qry(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
bool check(int mid, bool tp){
    unordered_map<ull,int> mp;
    for(int i=1;i+mid-1<=n;++i) mp[qry(i,i+mid-1)]++;
    ull same=0;
    //cout<<mid<<endl;
    for(auto &i:mp) {
        //cout<<i.F<<' '<<i.S<<endl;
        if(i.S>1) same = i.F;
    }
    //cout<<same<<endl;
    if(tp){
        for(int i=1;i+mid-1<=n;++i)
            if(qry(i,i+mid-1)==same) return cout<<s.substr(i-1,mid)<<"\n", 0;
    }else return same!=0;
}
signed main(){StarBurstStream
    cin>>s; n=s.size();
    p[0]=1;
    for(int i=1;i<=n;++i) h[i]=h[i-1]*base+s[i-1], p[i]=p[i-1]*base;
    int m,l=1,r=n,last;
    while(l<r){
        m=l+r>>1;
        if(check(m, 0)) last=m,l=m+1;
        else r=m;
    }
    check(last,1);
    return 0;
}
