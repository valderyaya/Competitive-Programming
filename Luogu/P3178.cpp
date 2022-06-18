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
const int mxn=100001;
struct edge{int to,nxt;}e[mxn<<1];
int n,m,dep[mxn],top[mxn],rnk[mxn],laz[mxn<<2],w[mxn],bom[mxn],dfn[mxn],seg[mxn<<2],fa[mxn],sz[mxn]={},son[mxn]={},tot=0,cnt=0,h[mxn]={};
inline void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs1(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dep[v]){
            dep[v]=dep[x]+1;
            fa[v]=x;
            dfs1(v);
            sz[x]+=sz[v];
            if(sz[v]>sz[son[x]]) son[x]=v;
        }
    }
}
int dfs2(int x,int t){
    top[x]=t;
    dfn[x]=bom[x]=++tot;
    rnk[tot]=x;
    if(son[x]) bom[x]=dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) bom[x]=max(bom[x],dfs2(v,v));
    }
    return bom[x];
}
void down(int l,int r,int rt){
    int mid=l+r>>1;
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    seg[rt<<1]+=laz[rt]*(mid-l+1);
    seg[rt<<1|1]+=laz[rt]*(r-mid);
    laz[rt]=0;
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=w[rnk[l]],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr) return seg[rt]+=v*(r-l+1),laz[rt]+=v,void();
    if(l!=r&&laz[rt]) down(l,r,rt);
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,v);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1]; 
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    if(l!=r&&laz[rt]) down(l,r,rt);
    int mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return query(mid+1,r,ql,qr,rt<<1|1);
    else return query(l,mid,ql,qr,rt<<1)+query(mid+1,r,ql,qr,rt<<1|1);
}
int que(int a,int b){
    int sum=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        sum+=query(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) a^=b^=a^=b;
    return sum+query(1,n,dfn[a],dfn[b],1);
}
main(){Rosario
    cin>>n>>m;
    int a,b,x;
    REP1(i,1,n) cin>>w[i];
    REP(i,n-1) cin>>a>>b,add(a,b),add(b,a);
    dep[1]=fa[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,n,1);
    // REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
    // REP1(i,1,n) cout<<bom[i]<<" \n"[i==n];
    // REP1(i,1,n) cout<<top[i]<<" \n"[i==n];
    // system("pause");
    while(m--){
        cin>>x>>a;
        //if(x==-1) cout<<query(1,n,dfn[a],dfn[a],1)<<"\n";
        if(x==1) cin>>b,modify(1,n,dfn[a],dfn[a],1,b);
        else if(x==2) cin>>b,modify(1,n,dfn[a],bom[a],1,b);
        else if(x==3)cout<<que(a,1)<<"\n";
    }
//    system("pause");
    return 0;
}
// 3 5 5 6 7
