#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

const int mxn=30001;
struct edge{int to,nxt;}e[mxn<<1];
pii seg[mxn<<2];// first-> max,sec-> sum
int n,m,dep[mxn],son[mxn],fa[mxn],sz[mxn],top[mxn],h[mxn]={},dfn[mxn],tot=0,rnk[mxn],w[mxn],cnt=0;

void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}

void dfs1(int x){
    son[x]=-1;
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dep[v]){
            fa[v]=x;
            dep[v]=dep[x]+1;
            dfs1(v);
            sz[x]+=sz[v];
            if(son[x]==-1||sz[v]>sz[son[x]]) son[x]=v;
        }
    }
}

void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rnk[tot]=x;
    if(son[x]==-1) return ;
    dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}

inline void up(int rt){
    seg[rt].F=max(seg[rt<<1].F,seg[rt<<1|1].F);
    seg[rt].S=seg[rt<<1].S+seg[rt<<1|1].S;
}

void build(int l,int r,int rt){
    if(l==r) return seg[rt].S=seg[rt].F=w[rnk[l]],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    up(rt);
}

void modify(int l,int r,int x,int rt,int v){
    if(l==r) return seg[rt].F=seg[rt].S=v,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1,v);
    else modify(mid+1,r,x,rt<<1|1,v);
    up(rt);
}

int qmax(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt].F;
    int mid=l+r>>1;
    if(qr<=mid) return qmax(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return qmax(mid+1,r,ql,qr,rt<<1|1);
    else return max(qmax(l,mid,ql,qr,rt<<1),qmax(mid+1,r,ql,qr,rt<<1|1));
}

int qsum(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt].S;
    int mid=l+r>>1;
    if(qr<=mid) return qsum(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return qsum(mid+1,r,ql,qr,rt<<1|1);
    else return  qsum(l,mid,ql,qr,rt<<1)+qsum(mid+1,r,ql,qr,rt<<1|1);
}

int query_max(int a,int b){
    int mx=-1e5;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        mx=max(mx,qmax(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) a^=b^=a^=b;
    return max(mx,qmax(1,n,dfn[a],dfn[b],1));
}

int query_sum(int a,int b){
    int sum=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        sum+=qsum(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) a^=b^=a^=b;
    return sum+qsum(1,n,dfn[a],dfn[b],1);
}

int main(){Rosario
    string s;
    cin>>n;
    int a,b;
    REP(i,n-1) cin>>a>>b,add(a,b),add(b,a);
    REP1(i,1,n) cin>>w[i];
    dep[1]=1;fa[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,n,1);
    cin>>m;
    while(m--){
        cin>>s>>a>>b;
        if(s[1]=='M') cout<<query_max(a,b)<<"\n";
        else if(s[1]=='S') cout<<query_sum(a,b)<<"\n";
        else modify(1,n,dfn[a],1,b);
    }
//    wait
    return 0;
}
