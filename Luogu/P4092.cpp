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
struct edge{int to,nxt;}e[z<<1];
int n,m,top[z],rnk[z],dfn[z],tot=0,cnt=0,h[z],son[z],sz[z],dep[z],seg[z<<2],fa[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
    e[++cnt]=edge{u,h[v]};
    h[v]=cnt;
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
    rnk[tot]=x;
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
void modify(int l,int r,int x,int rt){
    if(l==r) return seg[rt]=l,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1);
    else modify(mid+1,r,x,rt<<1|1);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,res=0;
    if(ql<=mid) res=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) res=max(res,query(mid+1,r,ql,qr,rt<<1|1));
    return res;
}
int que(int a,int b){
    int res=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=max(res,query(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    return max(res,query(1,n,dfn[a],dfn[b],1));
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    char c;
    REP(i,n-1) cin>>a>>b,add(a,b);
    dep[1]=1; dfs(1); dfs2(1,1);
    modify(1,n,dfn[1],1); 
    while(m--){
        cin>>c>>a;
        if(c=='Q') cout<<rnk[que(a,1)]<<'\n';
        else modify(1,n,dfn[a],1);
    }
//    system("pause");
    return 0;
}
