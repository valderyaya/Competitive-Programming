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

const int z=100005;
struct edge{int to,nxt,w;}e[z<<1];
int n,fa[z],h[z],cnt=0,tot=0,top[z],wz[z],seg[z<<2],dep[z],dfn[z],sz[z],son[z],rnk[z],U[z],V[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        wz[v]=e[i].w;fa[v]=x;
        dep[v]=dep[x]+1;
        dfs(v);
        sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    rnk[tot]=wz[x];
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=rnk[l],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
void modify(int l,int r,int x,int rt,int v){
    if(l==r) return seg[rt]=v,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1,v);
    else modify(mid+1,r,x,rt<<1|1,v);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,re=0;
    if(ql<=mid) re=max(re, query(l,mid,ql,qr,rt<<1));
    if(qr>mid) re=max(re, query(mid+1,r,ql,qr,rt<<1|1));
    return re;
}
int ret(int a,int b){
    if(a==b) return 0;
    int ans=0;
    while(top[a]^top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        ans=max(ans,query(1,n,dfn[top[a]],dfn[a],1));
        a=fa[top[a]];
    }
    if(dfn[a]>dfn[b]) a^=b^=a^=b;
    ans=max(ans,query(1,n,dfn[a]+1,dfn[b],1));
    return ans;
}
int main(){Rosario
    cin>>n;
    int a,b,c;
    string s;
    REP1(i,1,n-1) cin>>a>>b>>c,add(a,b,c),add(b,a,c),U[i]=a,V[i]=b;
    dep[1]=fa[1]=1;
    dfs(1);dfs2(1,1);build(1,n,1);
    // REP1(i,1,n) cout<<top[i]<<" \n"[i==n];
    // REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
    // wait
    while(cin>>s,s[0]!='D'){
        cin>>a>>b;
        if(s[0]=='Q') cout<<ret(a,b)<<"\n";
        else modify(1,n,dfn[dep[U[a]]>dep[V[a]]?U[a]:V[a]],1,b);
    }
//    wait
    return 0;
}
