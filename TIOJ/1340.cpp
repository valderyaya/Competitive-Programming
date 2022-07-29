#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

void rd(int &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar(x%10+48);
}
const int z=1e5+5,inf=1e9;
vector<pii> edge;
struct edge_{int to,nxt;}e[z<<1];
int dep[z],n,q,cnt,tot,h[z],lca[21][z],mn[21][z],pa[z],sz[z];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void add(int u,int v){
    e[++cnt]=edge_{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dep[v]=dep[x]+1;
        lca[0][v]=x, mn[0][v]=abs(x-v);
        dfs(v,x);
    }
}
int LCA(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    int ans=inf;
    for(int i=dep[y]-dep[x],k=0;i;i>>=1,++k)
        if(i&1) ans=min(ans,mn[k][y]),y=lca[k][y];
    if(x==y) return ans;
    for(int i=20;~i;--i)
        if(lca[i][x]!=lca[i][y]){
            ans=min({ans,mn[i][x],mn[i][y]});
            x=lca[i][x], y=lca[i][y];
        }
    return min({ans,mn[0][x],mn[0][y]});
}
signed main(){//StarBurstStream
    rd(n),rd(q);
    for(int i=1;i<=n;++i){
        pa[i]=i, sz[i]=1;
        for(int j=i+i;j<=n;j+=i)
            edge.em(j,j-i);
    }
    sort(ALL(edge),[&](pii x,pii y){return abs(x.F-x.S)>abs(y.F-y.S);});
    for(int x,y,i=0,j=edge.size();i<j;++i){
        x=fin(edge[i].F), y=fin(edge[i].S);
        if(x==y) continue;
        if(sz[x]>sz[y]) swap(x,y);
        pa[x]=y, sz[y]+=sz[x]; 
        add(edge[i].F,edge[i].S);
        add(edge[i].S,edge[i].F);
    }
    lca[0][1]=1; dfs(1,1);
    for(int i=1;i<21;++i)
        for(int j=1;j<=n;++j) mn[i][j]=min(mn[i-1][j],mn[i-1][lca[i-1][j]]),lca[i][j]=lca[i-1][lca[i-1][j]];
    for(int x,y;q--;){
        rd(x),rd(y);
        write(LCA(x,y));
        puts("");
    }
}
