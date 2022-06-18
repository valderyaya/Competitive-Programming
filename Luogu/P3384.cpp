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

#define int ll
const int z=1e5+5;
int cnt=0,top[z],dfn[z],fa[z],n,m,rt,mod,sz[z],son[z],dep[z],seg[z<<2],laz[z<<2],val[z],rk[z];
vector<int> v[z];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x]){
        if(dep[i]) continue;
        dep[i]=dep[x]+1;
        fa[i]=x;
        dfs(i);
        sz[x]+=sz[i];
        if(sz[son[x]]<sz[i]) son[x]=i;
    }
}
void dfs2(int x,int t){
    top[x]=t; dfn[x]=++cnt;
    rk[dfn[x]]=val[x];
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x]) if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
////////
#define ls rt<<1
#define rs ls|1
void down(int l,int r,int rt){
    if(!laz[rt]) return;
    laz[ls]=(laz[ls]+laz[rt])%mod;
    laz[rs]=(laz[rs]+laz[rt])%mod;
    int mid=l+r>>1;
    seg[ls]=(seg[ls]+(mid-l+1)*laz[rt]%mod)%mod;
    seg[rs]=(seg[rs]+(r-mid)*laz[rt]%mod)%mod;
    laz[rt]=0;
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=rk[l]%mod,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
    seg[rt]=(seg[rt<<1]+seg[rt<<1|1])%mod;
}
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        laz[rt]+=v; seg[rt]=(seg[rt]+(r-l+1)*v%mod)%mod;
        return;
    }down(l,r,rt); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,v);
    seg[rt]=(seg[ls]+seg[rs])%mod;
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(l,r,rt); int mid=l+r>>1,res=0;
    if(ql<=mid) res=query(l,mid,ql,qr,ls);
    if(qr>mid) res=(res+query(mid+1,r,ql,qr,rs))%mod;
    return res;
}
////////////////
void mdf(int a,int b,int v){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        modify(1,n,dfn[top[a]],dfn[a],1,v);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    modify(1,n,dfn[a],dfn[b],1,v);
}
int que(int a,int b){
    int res=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        res=(res+query(1,n,dfn[top[a]],dfn[a],1))%mod;
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    res=(res+query(1,n,dfn[a],dfn[b],1))%mod;
    return res;
}
 main(){Rosario
    cin>>n>>m>>rt>>mod;
    REP1(i,1,n) cin>>val[i];
    int x,y,opt,k;
    REP(i,n-1) cin>>x>>y,v[x].em(y),v[y].em(x);
    dep[rt]=1; dfs(rt); dfs2(rt,rt); build(1,n,1);
    while(m--){
        cin>>opt;
        if(opt==1) cin>>x>>y>>k,mdf(x,y,k);
        else if(opt==2) cin>>x>>y,cout<<que(x,y)<<"\n";
        else if(opt==3) cin>>x>>y,modify(1,n,dfn[x],dfn[x]+sz[x]-1,1,y);
        else cin>>x,cout<<query(1,n,dfn[x],dfn[x]+sz[x]-1,1)<<"\n";
    }
    return 0;
}
