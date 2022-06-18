//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=3e5+5;
struct edge{int to,nxt;}e[z<<1];
int dep[z],lca[z][20],h[z],cnt,n,m,w[z],b1[z],b2[z<<1],ans[z],ac[z];
pii p[z];
vector<pii> opt1[z],opt2[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dep[v]){
            lca[v][0]=x; dep[v]=dep[x]+1;
            dfs(v);
        }
    }
}
inline void build(){
    for(int j=1;j<20;++j)
        for(int i=1;i<=n;++i)
            lca[i][j]=lca[lca[i][j-1]][j-1];
}
int LCA(int a,int b){
    if(dep[a]>dep[b])swap(a,b);
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,++k) if(i&1) b=lca[b][k];
    if(a==b) return a;
    for(int i=19;~i;--i) if(lca[a][i]!=lca[b][i]) a=lca[a][i],b=lca[b][i];
    return lca[a][0];
}
void dfs1(int x){
    int bef=b1[dep[x]+w[x]];
    for(int i=h[x];i;i=e[i].nxt) if(e[i].to!=lca[x][0]) dfs1(e[i].to);
    for(auto &i:opt1[x]) b1[i.F]+=i.S;
    ans[x]+=b1[dep[x]+w[x]]-bef;
}
void dfs2(int x){
    int bef=b2[w[x]-dep[x]+z];
    for(int i=h[x];i;i=e[i].nxt) if(e[i].to!=lca[x][0]) dfs2(e[i].to);
    for(auto &i:opt2[x]) b2[i.F+z]+=i.S;
    ans[x]+=b2[w[x]-dep[x]+z]-bef;
}
int main(){Rosario
    cin>>n>>m;
    for(int a,b,i=1;i<n;++i) cin>>a>>b,add(a,b),add(b,a);
    REP1(i,1,n) cin>>w[i];
    REP1(i,1,m) cin>>p[i].F>>p[i].S;
    lca[1][0]=0;dep[1]=1; dfs(1); build();
    REP1(i,1,m){
        ac[i]=LCA(p[i].F,p[i].S);
        opt1[p[i].F].pb({dep[p[i].F],1});
        opt1[ac[i]].pb({dep[p[i].F],-1});
    }dfs1(1);
    REP1(i,1,m){
        int d=dep[p[i].F]+dep[p[i].S]-2*dep[ac[i]];
        opt2[p[i].S].pb({d-dep[p[i].S],1});
        if(lca[ac[i]][0]) opt2[lca[ac[i]][0]].pb({d-dep[p[i].S],-1});
    }dfs2(1);
    REP1(i,1,n) cout<<ans[i]<<' ';
    return 0;
}
