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

const int z=100005;
struct segment_{int l,r,cnt;}seg[z<<2];
struct edge{int to,nxt;}e[z<<1];
int lc,rc,top[z],dfn[z],laz[z<<2],tot=0,wei[z],rnk[z],cnt=0,h[z],sz[z],son[z],fa[z],dep[z],n,m;
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
    rnk[tot]=wei[x];
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
//-------------------------
void down(int rt){
    if(!laz[rt]) return;
    laz[rt<<1]=laz[rt<<1|1]=seg[rt<<1].l=seg[rt<<1|1].l=laz[rt];
    seg[rt<<1].r=seg[rt<<1|1].r=laz[rt];seg[rt<<1].cnt=seg[rt<<1|1].cnt=1;
    laz[rt]=0;
}
void up(int rt){
    seg[rt].l=seg[rt<<1].l;
    seg[rt].r=seg[rt<<1|1].r;
    seg[rt].cnt=seg[rt<<1].cnt+seg[rt<<1|1].cnt-(seg[rt<<1].r==seg[rt<<1|1].l?1:0);
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt].l=seg[rt].r=rnk[l],seg[rt].cnt=1,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
    up(rt);
}
void modify(int l,int r,int ql,int qr,int rt,int c){
    if(ql<=l&&r<=qr){
        seg[rt].l=seg[rt].r=c;seg[rt].cnt=1;
        laz[rt]=c; return;
    }down(rt); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,c);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,c);
    up(rt);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) {
        if(l==ql) lc=seg[rt].l;
        if(r==qr) rc=seg[rt].r;
        return seg[rt].cnt;
    }down(rt); int mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return query(mid+1,r,ql,qr,rt<<1|1);
    else return query(l,mid,ql,qr,rt<<1)+query(mid+1,r,ql,qr,rt<<1|1)-(seg[rt<<1].r==seg[rt<<1|1].l?1:0);
}
//----------------------------
void mod(int a,int b,int c){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        modify(1,n,dfn[top[a]],dfn[a],1,c);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    modify(1,n,dfn[a],dfn[b],1,c);
}
int que(int a,int b){
    int ret=0,x=0,y=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b),swap(x,y);
        ret+=query(1,n,dfn[top[a]],dfn[a],1)-(x==rc?1:0);
        x=lc,a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b),swap(x,y);
    ret+=query(1,n,dfn[a],dfn[b],1);
    if(lc==x) --ret;
    if(rc==y) --ret;
    return ret;
}
int main(){Rosario
    cin>>n>>m;int a,b,x;
    REP1(i,1,n) cin>>wei[i];
    REP(i,n-1) cin>>a>>b,add(a,b),add(b,a);
    char c;
    dep[1]=1; dfs(1); dfs2(1,1); build(1,n,1);
    while(m--){
        cin>>c>>a>>b;
        if(c=='C') cin>>x,mod(a,b,x);
        else cout<<que(a,b)<<"\n";
    }
//    system("pause");
    return 0;
}
