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
struct edge{int to,nxt,w;}e[z<<1];
int top[z],dfn[z],sz[z],fa[z],son[z],dep[z],h[z],cnt=0,tot=0,laz[z<<2],seg[z<<2],n,lz[z<<2],w[z],rnk[z];
void add(int u,int v,int we){
    e[++cnt]=edge{v,h[u],we};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        dep[v]=dep[x]+1; fa[v]=x; w[v]=e[i].w;
        dfs(v); sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rnk[tot]=w[x];
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=rnk[l],void();
    int m=l+r>>1;lz[rt]=-1;
    build(l,m,rt<<1); build(m+1,r,rt<<1|1);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
void down(int rt){
    if(lz[rt]>=0){
        lz[rt<<1]=lz[rt<<1|1]=seg[rt<<1]=seg[rt<<1|1]=lz[rt];
        laz[rt<<1]=laz[rt<<1|1]=0;lz[rt]=-1;
    }
    if(laz[rt]){
        laz[rt<<1]+=laz[rt];
        laz[rt<<1|1]+=laz[rt];
        seg[rt<<1]+=laz[rt];
        seg[rt<<1|1]+=laz[rt];
        laz[rt]=0;
    }
}
void modify(int l,int r,int ql,int qr,int rt,int v,int tag){//1 change,0 add
    if(ql<=l&&r<=qr){
        if(tag){
            seg[rt]=v;
            lz[rt]=v;laz[rt]=0;
        }else{
            seg[rt]+=v;
            laz[rt]+=v;
        }return;
    }down(rt); int m=l+r>>1;
    if(ql<=m) modify(l,m,ql,qr,rt<<1,v,tag);
    if(qr>m) modify(m+1,r,ql,qr,rt<<1|1,v,tag);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
int que(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(rt);int m=l+r>>1,res=0;
    if(ql<=m) res=que(l,m,ql,qr,rt<<1);
    if(qr>m) res=max(res,que(m+1,r,ql,qr,rt<<1|1));
    return res;
}
int get(int a,int b){
    int res=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=max(res,que(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    if(a!=b) res=max(res,que(1,n,dfn[a]+1,dfn[b],1));
    return res;
}
void mod(int a,int b,int c,int tag){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        modify(1,n,dfn[top[a]],dfn[a],1,c,tag);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    if(a!=b) modify(1,n,dfn[a]+1,dfn[b],1,c,tag);
}
pii ed[z];
int main(){Rosario
    cin>>n;
    int a,b,c;
    REP1(i,1,n-1) cin>>a>>b>>c,add(a,b,c),add(b,a,c),ed[i]=mkp(a,b);
    dep[1]=1; dfs(1); dfs2(1,1); build(1,n,1);
    string s;
    while(cin>>s,s!="Stop"){
        if(s[0]=='M') cin>>a>>b,cout<<get(a,b)<<"\n";
        else if(s[0]=='A') cin>>a>>b>>c,mod(a,b,c,0);
        else if(s[1]=='o') cin>>a>>b>>c,mod(a,b,c,1);
        else cin>>a>>b,c=max(dfn[ed[a].F],dfn[ed[a].S]),modify(1,n,c,c,1,b,1);
    }
//    system("pause");
    return 0;
}
