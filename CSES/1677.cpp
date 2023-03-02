//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
int n,m,k,pa[z],sz[z],now,ans[z<<1];
map<pii,bool> mp;
pii v[z<<1];
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
void merge(int x,int y){
    if(x==y) return;
    if(sz[x]>sz[y]) pa[y]=x, sz[x]+=sz[y];
    else pa[x]=y, sz[y]+=sz[x];
    --now;
}
signed main(){Rosario
    cin>>n>>m>>k;
    now=n;
    REP1(i,1,n) pa[i]=i;
    for(int x,y;m--;){
        cin>>x>>y;
        if(x>y)swap(x,y);
        mp[{x,y}]=1;
    }
    for(int i=0;i<k;++i) {
        cin>>v[i].F>>v[i].S;
        if(v[i].F>v[i].S) swap(v[i].F,v[i].S);
        mp[{v[i].F,v[i].S}]=0;
    }
    for(auto &i:mp) if(i.S) merge(fin(i.F.F),fin(i.F.S));
    for(int i=k-1;i>=0;--i){
        ans[i]=now;
        merge(fin(v[i].F),fin(v[i].S));
    }
    for(int i=0;i<k;++i) cout<<ans[i]<<' ';
    return 0;
}
