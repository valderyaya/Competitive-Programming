//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

#define int ll
const int z=100005;
struct edge{int to,nxt;}e[z<<1];
int top[z],h[z],cnt=0,tot=0,dfn[z],laz[z<<2],fa[z],son[z],sz[z],dep[z],seg[z<<2],n,q;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        dep[v]=dep[x]+1; fa[v]=x;
        dfs(v); sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
//--------------
void down(int l,int r,int rt){
    if(!laz[rt]) return ;
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    int m=l+r>>1;
    seg[rt<<1]+=(m-l+1)*laz[rt];
    seg[rt<<1|1]+=(r-m)*laz[rt];
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        seg[rt]+=(r-l+1)*v;
        laz[rt]+=v; return;
    }int m=l+r>>1;
    down(l,r,rt);
    if(ql<=m) modify(l,m,ql,qr,rt<<1,v);
    if(qr>m) modify(m+1,r,ql,qr,rt<<1|1,v);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(l,r,rt);int m=l+r>>1,s=0;
    if(ql<=m) s=query(l,m,ql,qr,rt<<1);
    if(qr>m) s+=query(m+1,r,ql,qr,rt<<1|1);
    return s;
}
void mod(int a,int b,int c){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        modify(1,n,dfn[top[a]],dfn[a],1,c);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    modify(1,n,dfn[a],dfn[b],1,c);
}
main(){Rosario
    cin>>n;
    char c;
    int a,b,d;
    REP(i,n-1) cin>>a>>b,++a,++b,add(a,b),add(b,a);
    dep[1]=1; dfs(1); dfs2(1,1);
    cin>>q;
    while(q--){
        cin>>c;
        if(c=='A') cin>>a>>b>>d,++a,++b,mod(a,b,d);
        else cin>>a,++a,cout<<query(1,n,dfn[a],dfn[a]+sz[a]-1,1)<<"\n";
    }   
//    system("pause");
    return 0;
}
