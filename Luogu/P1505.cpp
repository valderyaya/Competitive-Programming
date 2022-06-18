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

const int z=200005;
struct edge{int to,nxt,w;}e[z<<1];
int n,h[z],tot=0,cnt=0,we[z],fa[z],top[z],dfn[z],sz[z],son[z],seg[z<<2],mx[z<<2],mi[z<<2],m,laz[z<<2],dep[z],rnk[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        dep[v]=dep[x]+1; fa[v]=x;
        dfs(v);
        sz[x]+=sz[v]; we[v]=e[i].w;
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rnk[tot]=we[x];
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
//----------------------------------
void up(int rt){
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void p(int rt){
    laz[rt]^=1;
    seg[rt]*=-1;
    int tmp=mi[rt];
    mi[rt]=-mx[rt]; mx[rt]=-tmp;
}
void down(int rt){
    if(!laz[rt]) return;
    p(rt<<1); p(rt<<1|1);
    laz[rt]=0;
}
void modify(int l,int r,int x,int rt,int v){
    if(l==r) return mx[rt]=mi[rt]=seg[rt]=v,void();
    down(rt); int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1,v);
    else modify(mid+1,r,x,rt<<1|1,v);
    up(rt);
}
void rev(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return p(rt),void();
    down(rt); int mid=l+r>>1;
    if(ql<=mid) rev(l,mid,ql,qr,rt<<1);
    if(qr>mid) rev(mid+1,r,ql,qr,rt<<1|1);
    up(rt);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(rt); int mid=l+r>>1,s=0;
    if(ql<=mid) s=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) s+=query(mid+1,r,ql,qr,rt<<1|1);
    return s;
}
int qmax(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return mx[rt];
    down(rt); int mid=l+r>>1,s=-1e9;
    if(ql<=mid) s=qmax(l,mid,ql,qr,rt<<1);
    if(qr>mid) s=max(s,qmax(mid+1,r,ql,qr,rt<<1|1));
    return s;
}
int qmin(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return mi[rt];
    down(rt); int mid=l+r>>1,s=1e9;
    if(ql<=mid) s=qmin(l,mid,ql,qr,rt<<1);
    if(qr>mid) s=min(s,qmin(mid+1,r,ql,qr,rt<<1|1));
    return s;
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=mx[rt]=mi[rt]=rnk[l],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
    up(rt);
}
//-----------------
int sum(int a,int b){
    int res=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res+=query(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(a==b) return res;
    if(dep[a]>dep[b]) swap(a,b);
    return res+query(1,n,dfn[a]+1,dfn[b],1);
}
void modrev(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        rev(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(a==b) return ;
    if(dep[a]>dep[b]) swap(a,b);
    rev(1,n,dfn[a]+1,dfn[b],1);
}
int gmax(int a,int b){
    int res=-1e9;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=max(res,qmax(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(a==b) return res;
    if(dep[a]>dep[b]) swap(a,b);
    return max(res,qmax(1,n,dfn[a]+1,dfn[b],1));
}
int gmin(int a,int b){
    int res=1e9;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=min(res,qmin(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(a==b) return res;
    if(dep[a]>dep[b]) swap(a,b);
    return min(res,qmin(1,n,dfn[a]+1,dfn[b],1));
}
pii g[z];
int main(){Rosario
    cin>>n;
    int a,b,c;
    REP1(i,1,n-1){
        cin>>a>>b>>c;
        a++,b++;
        add(a,b,c);add(b,a,c);
        g[i]=mkp(a,b);
    }
    dep[1]=1;
    dfs(1); dfs2(1,1); build(1,n,1);
    cin>>m;
    string str;
    while(m--){
        cin>>str>>a>>b; a++,b++;
        if(str[0]=='C') a--,b--,modify(1,n,max(dfn[g[a].F],dfn[g[a].S]),1,b);
        else if(str[0]=='N') modrev(a,b);
        else if(str[0]=='S') cout<<sum(a,b)<<"\n";
        else if(str[1]=='A') cout<<gmax(a,b)<<"\n";
        else cout<<gmin(a,b)<<"\n";
    }
//    system("pause");
    return 0;
}
