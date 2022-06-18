//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
const int z=1e5+5;
int sz[z<<6],sum[z<<6],rt[z],lc[z<<6],rc[z<<6],n,m,cnt,b[z];
void mdf(int l,int r,int x,int v,int &o,int pre){
    o=++cnt;
    lc[o]=lc[pre],rc[o]=rc[pre],sz[o]=sz[pre],sum[o]=sum[pre];
    sum[o]+=v*b[x]; sz[o]+=v;
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) mdf(l,mid,x,v,lc[o],lc[pre]);
    else mdf(mid+1,r,x,v,rc[o],rc[pre]);
}
int qry(int o,int k,int l,int r){
    if(l==r) return sum[o]/sz[o]*k;
    int mid=l+r>>1;
    if(sz[lc[o]]>=k) return qry(lc[o],k,l,mid);
    else return sum[lc[o]]+qry(rc[o],k-sz[lc[o]],mid+1,r);
}
vector<pii> tme[z];
signed main(){Rosario
    cin>>n>>m;
    for(int l,r,x,i=1;i<=n;++i){
        cin>>l>>r>>x; b[i]=x;
        tme[l].em(x,1);
        tme[r+1].em(x,-1);
    }
    sort(b+1,b+1+n); int len=unique(b+1,b+1+n)-b-1;
    REP1(i,1,m){
        rt[i]=rt[i-1];
        for(auto &j:tme[i]){
            int pos=lower_bound(b+1,b+1+len,j.F)-b;
            mdf(1,len,pos,j.S,rt[i],rt[i]);
        }
    }
    int pre=1;
    for(int a,b,c,x,i=0;i<m;++i){
        cin>>x>>a>>b>>c;
        pre=1+(a*pre+b)%c;
        if(pre>=sz[rt[x]]) pre=sum[rt[x]];
        else pre=qry(rt[x],pre,1,len);
        cout<<pre<<"\n";
    }
    return 0;
}
