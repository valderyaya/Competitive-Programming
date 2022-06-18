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

const int z=100005,inf=1e9;
int n,m,fa[z],top[z],dep[z],son[z]={},dfn[z],sz[z],rnk[z],seg[z<<2],tot=0;
vector<int> v[z];
void dfs1(int x){
    sz[x]=1;
    for(auto &i:v[x]){
        if(!dep[i]){
            fa[i]=x;
            dep[i]=dep[x]+1;
            dfs1(i);
            sz[x]+=sz[i];
            if(sz[i]>sz[son[x]]) son[x]=i;
        }
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rnk[tot]=x;
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x])
        if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=inf,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
void modify(int l,int r,int x,int rt){
    if(l==r) return seg[rt]= seg[rt]==inf?x:inf ,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1);
    else modify(mid+1,r,x,rt<<1|1);
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return query(mid+1,r,ql,qr,rt<<1|1);
    else return min(query(l,mid,ql,qr,rt<<1),query(mid+1,r,ql,qr,rt<<1|1));
}
int ret(int x){
    int ans=inf;
    while(top[x]!=1){
        ans=min(ans,query(1,n,dfn[top[x]],dfn[x],1));
        x=fa[top[x]];
    }
    ans=min(ans,query(1,n,1,dfn[x],1));
    return ans==inf?-1:rnk[ans];
}
int main(){Rosario
    cin>>n>>m;
    int a,b,x;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    fa[1]=dep[1]=1;
    dfs1(1);dfs2(1,1);build(1,n,1);
    // REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
    // wait
    while(m--){
        cin>>a>>b;
        if(a) cout<<ret(b)<<"\n";
        else modify(1,n,dfn[b],1);
    }
//    system("pause");
    return 0;
}
