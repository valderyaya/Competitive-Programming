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

const int z=1e5+5,Z=z*120;
struct edge{int to,nxt;}e[z<<1];
int tot=0,cnt=0,h[z],n,m,dep[z],lca[20][z],a[z],b[z],rs[Z],ls[Z],val[Z],len,p[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void build_lca(){REP1(j,1,17) REP1(i,1,n) lca[j][i]=lca[j-1][lca[j-1][i]];}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=dep[a]-dep[b],k=0;i;i>>=1,++k) if(i&1) a=lca[k][a];
    if(a==b) return a;
    for(int i=17;~i;--i) if(lca[i][a]!=lca[i][b]) a=lca[i][a],b=lca[i][b];
    return lca[0][a];
}
void build_tree(int l,int r,int &rt){
    rt=++tot; val[rt]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build_tree(l,mid,ls[rt]),build_tree(mid+1,r,rs[rt]);
}
void inse(int l,int r,int x,int &rt,int pre){
    rt=++tot; rs[rt]=rs[pre],ls[rt]=ls[pre],val[rt]=val[pre]+1;
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) inse(l,mid,x,ls[rt],ls[pre]);
    else inse(mid+1,r,x,rs[rt],rs[pre]);
}
void dfs(int x,int pa){
    inse(1,len,lower_bound(b+1,b+1+len,a[x])-b,p[x],p[pa]);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        dep[v]=dep[x]+1; lca[0][v]=x;
        dfs(v,x);
    }
}
int query(int l,int r,int A,int B,int lc,int fa,int k){
    if(l==r) return l;
    int x=val[ls[A]]+val[ls[B]]-val[ls[lc]]-val[ls[fa]],mid=l+r>>1;
    if(k<=x) return query(l,mid,ls[A],ls[B],ls[lc],ls[fa],k);
    return query(mid+1,r,rs[A],rs[B],rs[lc],rs[fa],k-x);
}
int main(){Rosario
    //freopen("P2633_1.in","r",stdin);
    cin>>n>>m;
    REP1(i,1,n)cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n); len=unique(b+1,b+1+n)-b-1;
    int x,y,k,last=0;
    REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
    dep[1]=1;  build_tree(1,len,p[0]); dfs(1,0); build_lca();
    while(m--){
        cin>>x>>y>>k;
        x^=last;
        int lc=LCA(x,y),fa=lca[0][lc];
        last=b[query(1,len,p[x],p[y],p[lc],p[fa],k)];
        cout<<last<<"\n"; 
    }
    return 0;
}
