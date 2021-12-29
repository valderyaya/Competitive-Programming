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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

#define int ll
const int z=2e5+5;
int top[z],dep[z],dfn[z],tot,n,m,a[z],son[z],sz[z],fa[z],rk[z],seg[z<<2];
vector<int> v[z];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x])
        if(!dep[i]){
            fa[i]=x;
            dep[i]=dep[x]+1;
            dfs(i);
            if(sz[i]>sz[son[x]]) son[x]=i;
        }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rk[tot]=a[x];
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x]) if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
#define ls rt<<1
#define rs ls|1
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=rk[l],void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    seg[rt]=max(seg[ls],seg[rs]);
}
void mdf(int l,int r,int x,int rt,int val){
    if(l==r) return seg[rt]=val,void();
    int mid=l+r>>1;
    if(x<=mid) mdf(l,mid,x,ls,val);
    else mdf(mid+1,r,x,rs,val);
    seg[rt]=max(seg[ls],seg[rs]);
}
int que(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,ret=0;
    if(ql<=mid) ret=que(l,mid,ql,qr,ls);
    if(qr>mid) ret=max(ret,que(mid+1,r,ql,qr,rs));
    return ret;
}
int qry(int x,int y){
    int ret=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ret=max(ret,que(1,n,dfn[top[x]],dfn[x],1));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    return max(ret,que(1,n,dfn[x],dfn[y],1));
}
signed main(){Aincrad
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    for(int i=1,x,y;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
    dep[1]=1; dfs(1); dfs2(1,1);
    build(1,n,1);
    for(int k,y,x;m--;){
        cin>>k>>x>>y;
        if(k==1) mdf(1,n,dfn[x],1,y);
        else cout<<qry(x,y)<<" ";
    }
    return 0;
}
