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

const int z=2e5+1;
int n,m,e,q,tot,ans[500005],pa[z],sz[z],qry[500005],esz[z];
pii edge[500005];
bitset<500005> del;
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void mer(int x,int y){
    x=fin(x), y=fin(y);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    if(esz[x]) tot-=sz[x]-esz[x];
    if(esz[y]) tot-=sz[y]-esz[y];
    pa[x]=y; sz[y]+=sz[x], esz[y]+=esz[x];
    if(esz[y]) tot+=sz[y]-esz[y];
}
signed main(){StarBurstStream
    cin>>n>>m>>e;
    for(int i=1;i<=n+m;++i){
        pa[i]=i;
        sz[i]=1;
        if(i>n) esz[i]=1;
    }
    for(int i=0;i<e;++i) 
        cin>>edge[i].F>>edge[i].S;
    cin>>q;
    for(int i=0;i<q;++i) cin>>qry[i],--qry[i],del[qry[i]]=1;
    for(int i=0;i<e;++i)
        if(!del[i]) mer(edge[i].F,edge[i].S);
    for(int i=q-1;~i;--i){
        ans[i]=tot;
        mer(edge[qry[i]].F,edge[qry[i]].S);
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<"\n";
}



