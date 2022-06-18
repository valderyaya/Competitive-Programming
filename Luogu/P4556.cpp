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
struct seg{int ls,rs,ans,sum;}a[z*60];
struct edge{int to,nxt;}e[z<<1];
int lca[z][20],n,m,h[z],dep[z],cnt,tot,root[z],ans[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs1(int x){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        lca[v][0]=x; dep[v]=dep[x]+1;
        dfs1(v);
    }
}
inline void build(){
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++) lca[i][j]=lca[lca[i][j-1]][j-1];
}
int Lca(int x,int y){
    if(dep[x]>dep[y]) x^=y^=x^=y;
    for(int i=dep[y]-dep[x],k=0;i;i>>=1,k++) if(i&1) y=lca[y][k];
    if(x==y) return x;
    for(int i=19;~i;--i) if(lca[x][i]!=lca[y][i]) x=lca[x][i],y=lca[y][i];
    return lca[x][0];
}
void up(int rt){
    int ls=a[rt].ls,rs=a[rt].rs;
    if(a[ls].sum>=a[rs].sum) a[rt].sum=a[ls].sum,a[rt].ans=a[ls].ans;
    else a[rt].sum=a[rs].sum,a[rt].ans=a[rs].ans;
}
void modify(int &rt,int l,int r,int x,int c){
    if(!rt) rt=++tot;
    if(l==r) return a[rt].ans=l,a[rt].sum+=c,void();
    int mid=l+r>>1;
    if(x<=mid) modify(a[rt].ls,l,mid,x,c);
    else modify(a[rt].rs,mid+1,r,x,c);
    up(rt);
}
int merge(int x,int y,int l,int r){
    if(!x||!y) return x|y;
    if(l==r) return a[x].sum+=a[y].sum,a[x].ans=(a[x].sum?l:0),x;
    int mid=l+r>>1;
    a[x].ls=merge(a[x].ls,a[y].ls,l,mid);
    a[x].rs=merge(a[x].rs,a[y].rs,mid+1,r);
    up(x); return x;
}
void dfs2(int x,int p){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dfs2(v,x);
        root[x]=merge(root[x],root[v],1,z-1);
    }
    ans[x]=a[root[x]].ans;
}
int main(){Rosario
    cin>>n>>m;
    int x,y,c,rt;
    REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
    lca[1][0]=dep[1]=1; dfs1(1); build();
    while(m--){
        cin>>x>>y>>c;
        rt=Lca(x,y);
        modify(root[x],1,z-1,c,1);
        modify(root[y],1,z-1,c,1);
        modify(root[rt],1,z-1,c,-1);
        if(rt!=1) modify(root[lca[rt][0]],1,z-1,c,-1);
    }
    dfs2(1,0);
    REP1(i,1,n) cout<<ans[i]<<"\n";
    return 0;
}
