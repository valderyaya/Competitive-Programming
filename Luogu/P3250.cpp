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
#define wait system("pause");

inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
const int z=1e5+5;
struct edge{int to,nxt;}e[z<<1];
int h[z],cnt=0,dfn[z],n,m,top[z],son[z],sz[z],dep[z],tot,fa[z],ans,opt;
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
    top[x]=t; dfn[x]=++tot;
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
struct segment{
    priority_queue<int> q[2];
    int top(){
        while(!q[1].empty()&&q[0].top()==q[1].top()) q[0].pop(),q[1].pop();
        return q[0].empty()?-1:q[0].top();
    }
}seg[z<<2];
void modify(int l,int r,int ql,int qr,int rt,int c){
    if(ql<=l&&r<=qr) return seg[rt].q[opt].emplace(c),void();
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,c);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,c);
}
void query(int l,int r,int x,int rt){
    ans=max(ans,seg[rt].top());
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) query(l,mid,x,rt<<1);
    else query(mid+1,r,x,rt<<1|1); 
}
pii tmp[z];
void mod(int a,int b,int c){
    int idx=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        tmp[++idx]=mkp(dfn[top[a]],dfn[a]);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    tmp[++idx]=mkp(dfn[a],dfn[b]);
    sort(tmp+1,tmp+1+idx);
    REP1(i,1,idx) if(tmp[i-1].S+1<=tmp[i].F-1) modify(1,n,tmp[i-1].S+1,tmp[i].F-1,1,c);
    if(tmp[idx].S+1<=n) modify(1,n,tmp[idx].S+1,n,1,c);
}
struct que{int u,v,c;}qe[z<<1];
int main(){//Rosario
    n=read(),m=read();
    int x,u,v;
    REP(i,n-1) u=read(),v=read(),add(u,v),add(v,u);
    dep[1]=fa[1]=1 ; dfs(1); dfs2(1,1);
    // REP1(i,1,n) cout<<top[i]<<" \n"[i==n];
    // REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
    REP1(i,1,m){
        opt=read();
        if(opt==0) qe[i].u=read(),qe[i].v=read(),qe[i].c=read(),mod(qe[i].u,qe[i].v,qe[i].c);
        else if(opt==1) x=read(),mod(qe[x].u,qe[x].v,qe[x].c);
        else x=read(),ans=-1,query(1,n,dfn[x],1),printf("%d\n",ans);
    }
//    system("pause");
    return 0;
}
