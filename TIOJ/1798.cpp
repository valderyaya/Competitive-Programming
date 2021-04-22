//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1000005;
int son[z]={},sz[z]={},dfn[z]={},h[z]={},cnt=0,now=0,sum[z]={},n,m,k,q,dep[z],top[z],fa[z];
struct edge{int to,nxt;}e[z<<1];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        fa[v]=x; dep[v]=dep[x]+1;
        dfs(v); sz[x]+=sz[v];
        if(sz[son[x]]<sz[v]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t; dfn[x]=++now;
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt) if(e[i].to!=fa[x]&&e[i].to!=son[x]) dfs2(e[i].to,e[i].to);
}
void opt(int a,int b){
    while(top[a]^top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        ++sum[dfn[top[a]]],--sum[dfn[a]+1];
        a=fa[top[a]];
    }
    if(a!=b){
        if(dep[a]<dep[b]) swap(a,b);
        ++sum[dfn[b]+1],--sum[dfn[a]+1];
    }
}
int query(int a,int b){
    int res=0;
    while(top[a]^top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res+=sum[dfn[a]]-sum[dfn[top[a]]-1];
        a=fa[top[a]];
    }
    if(a!=b){
        if(dep[a]<dep[b]) swap(a,b);
        res+=sum[dfn[a]]-sum[dfn[b]];
    }
    return res==0;
}
int main(){Rosario
    cin>>n>>m>>k>>q;
    int x,y;
    while(m--) cin>>x>>y,add(x,y),add(y,x);
    dep[0]=1,dep[1]=2,fa[1]=0; dfs(1); dfs2(1,1);
    // REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
    // REP1(i,1,n) cout<<top[i]<<" \n"[i==n];
    while(k--) cin>>x>>y,opt(x,y);
    REP1(i,1,n) sum[i]+=sum[i-1];
    REP1(i,1,n) sum[i]=!sum[i];
    REP1(i,1,n) sum[i]+=sum[i-1];
    while(q--) cin>>x>>y,cout<<query(x,y)<<"\n";
    return 0;
}
