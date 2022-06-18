//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=5e4+5,inf=1e9;
int dep[z],cnt=0,fa[z],top[z],dfn[z],sz[z],son[z],n,m,seg[z<<2],laz[z<<2];
vector<int> v[z];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x])
        if(!dep[i]){
            dep[i]=dep[x]+1;  fa[i]=x;
            dfs(i);  sz[x]+=sz[i];
            if(sz[son[x]]<sz[i]) son[x]=i;
        }
}
void dfs2(int x,int t){
    top[x]=t; dfn[x]=++cnt;
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x]) if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}

#define ls rt<<1
#define rs ls|1
void build(int l,int r,int rt){
    laz[rt]=seg[rt]=inf;
    if(l==r) return;
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
}
void down(int rt){
    if(laz[rt]==inf) return;
    laz[ls]=min(laz[ls],laz[rt]);
    laz[rs]=min(laz[rs],laz[rt]);
    seg[ls]=min(laz[rt],seg[ls]);
    seg[rs]=min(laz[rt],seg[rs]);
    laz[rt]=inf;
}
void modify(int l,int r,int ql,int qr,int rt,int val){
    if(ql<=l&&r<=qr) return laz[rt]=min(laz[rt],val),seg[rt]=min(seg[rt],val),void();
    down(rt); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,val);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,val);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(rt); int mid=l+r>>1,res=inf;
    if(ql<=mid) res=query(l,mid,ql,qr,ls);
    if(qr>mid) res=min(res,query(mid+1,r,ql,qr,rs));
    return res;
}

void mdf(int a,int b,int val){
    while(top[a]^top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        modify(1,n,dfn[top[a]],dfn[a],1,val);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    if(dep[a]!=dep[b]) modify(1,n,dfn[a]+1,dfn[b],1,val);
}
int que(int a,int b){
    int res=inf;
    while(top[a]^top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=min(res,query(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    if(dep[a]!=dep[b]) res=min(res,query(1,n,dfn[a]+1,dfn[b],1));
    return res;
}
pii qe[z];
int main(){Rosario
    cin>>n>>m;
    int x,y,c;  dep[1]=1;
    REP(i,n-1) cin>>x>>y,v[x].em(y),v[y].em(x),qe[i]={x,y};
    dfs(1); dfs2(1,1); build(1,n,1);
    while(m--) cin>>x>>y>>c,mdf(x,y,c);
    REP(i,n-1){
        x=que(qe[i].F,qe[i].S);
        cout<<(x==inf?-1:x)<<"\n";
    }
    return 0;
}
