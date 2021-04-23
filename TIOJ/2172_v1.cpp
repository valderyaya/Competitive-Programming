//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+1;
struct edge{int to,nxt;}e[z<<1];
int n,m,cnt=0,h[z],dep[z],lca[z][20];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dep[v]) dep[v]=dep[x]+1,lca[v][0]=x,dfs(v);
    }
}
void build(){
    for(int j=1;j<20;++j)
        for(int i=0;i<n;++i) lca[i][j]=lca[lca[i][j-1]][j-1];
}
int Lca(int a,int b){
    if(dep[a]>dep[b]) a^=b^=a^=b;
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,++k)
        if(i&1) b=lca[b][k];
    if(a==b) return a;
    for(int i=19;~i;--i)
        if(lca[a][i]!=lca[b][i]) a=lca[a][i],b=lca[b][i];
    return lca[a][0];
}
int main(){Rosario
    cin>>n>>m;
    int x,y,p;
    REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
    dep[0]=1; dfs(0); build();
    while(m--) cin>>x>>y,p=Lca(x,y),cout<<dep[x]+dep[y]-dep[p]-dep[p]<<"\n";
    return 0;
}
