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

#define int ll
const int z=1e5+5;
inline int read(){
    int x=0;char c=getchar_unlocked();
    while(c>'9'||c<'0') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
    return x;
}
struct edge{int to,nxt,w;}e[z<<1];
bool col[z];
int sumc=0,sumd=0,n,rnk[z],m,h[z],dis[z],wei[z],top[z],dfn[z],son[z],sz[z],fa[z],cnt=0,tot=0,tre[z<<2],seg[z<<2],laz[z<<2];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa[x]) continue;
        dis[v]=dis[x]+e[i].w; fa[v]=x; wei[v]=e[i].w;
        dfs(v); sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    rnk[dfn[x]=++tot]=wei[x];
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
//-------------------------------
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=rnk[l],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void down(int rt){
    if(!laz[rt]) return;
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    tre[rt<<1]+=laz[rt]*seg[rt<<1];
    tre[rt<<1|1]+=laz[rt]*seg[rt<<1|1];
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt){
    if(ql>qr) return;
    if(ql<=l&&r<=qr) return tre[rt]+=seg[rt],laz[rt]++,void();
    down(rt); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1);
    tre[rt]=tre[rt<<1]+tre[rt<<1|1];
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql>qr) return 0;
    if(ql<=l&&r<=qr) return tre[rt];
    down(rt); int mid=l+r>>1,sum=0;
    if(ql<=mid) sum=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) sum+=query(mid+1,r,ql,qr,rt<<1|1);
    return sum;
}
//-----------------------
void mod(int x){
    sumd+=dis[x];
    sumc++;
    while(x){
        modify(1,n,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
}
int que(int x){
    int res=sumc*dis[x]+sumd;
    while(x){
        res-=2*query(1,n,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
    return res;
}
main(){//Rosario
    n=read(),m=read();//cin>>n>>m;
    int a,b,c;
    REP(i,n-1) a=read()+1,b=read()+1,c=read(),add(a,b,c),add(b,a,c);
    dfs(1); dfs2(1,1); build(1,n,1);
    while(m--){
        a=read(),c=read()+1;
        if(a==1){
            if(!col[c]) col[c]=1,mod(c);
        }else printf("%lld\n",que(c));
    }
//    system("pause");
    return 0;
}
