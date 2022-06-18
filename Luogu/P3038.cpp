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
#define wait system("pause");

const int z=100005;
struct edge{int to,nxt;}e[z<<1];
int tot=0,fa[z],dep[z]={},cnt=0,n,m,top[z],laz[z<<2]={},dfn[z],sz[z],son[z],h[z],seg[z<<2]={};
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        fa[v]=x;dep[v]=dep[x]+1;
        dfs(v);
        sz[x]+=sz[v];
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
void down(int l,int r,int rt){
    if(laz[rt]==0) return;
    int mid=l+r>>1;
    laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
    seg[rt<<1]+=(mid-l+1)*laz[rt],seg[rt<<1|1]+=(r-mid)*laz[rt];
    laz[rt]=0;
}
int query(int l,int r,int x,int rt){
    if(l==r) return seg[rt];
    down(l,r,rt);int mid=l+r>>1;
    if(x<=mid) return query(l,mid,x,rt<<1);
    else return query(mid+1,r,x,rt<<1|1);
}
void modify(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt]+=(r-l+1),laz[rt]++,void();
    down(l,r,rt);int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void pre(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        modify(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) a^=b^=a^=b;
    modify(1,n,dfn[a]+1,dfn[b],1);
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    char c;
    REP(i,n-1) cin>>a>>b,add(a,b),add(b,a);
    dep[1]=1;dfs(1);dfs2(1,1);
    while(m--){
        cin>>c>>a>>b;
        if(c=='Q') cout<<query(1,n,max(dfn[a],dfn[b]),1)<<"\n";
        else pre(a,b);
    }
//    system("pause");
    return 0;
}
