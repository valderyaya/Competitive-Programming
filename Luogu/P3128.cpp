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

const int z=50001;
int n,m,laz[z<<2],son[z],fa[z],top[z],dfn[z],sz[z],seg[z<<2],dep[z],tot=0;
vector<int> v[z];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x]){
        if(dep[i]) continue;
        dep[i]=dep[x]+1;
        fa[i]=x;
        dfs(i);
        sz[x]+=sz[i];
        if(sz[i]>sz[son[x]]) son[x]=i;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x])
        if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
void down(int l,int r,int rt){
    if(!laz[rt]) return;
    int mid=l+r>>1;
    laz[rt<<1]+=laz[rt];laz[rt<<1|1]+=laz[rt];
    seg[rt<<1]+=laz[rt],seg[rt<<1|1]+=laz[rt];
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt]++,++laz[rt],void();
    down(l,r,rt);int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
void zz(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) a^=b^=a^=b;
        modify(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) a^=b^=a^=b;
    modify(1,n,dfn[a],dfn[b],1);
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    dep[1]=fa[1]=1;
    dfs(1);dfs2(1,1);
    while(m--) cin>>a>>b,zz(a,b);
    cout<<seg[1]<<"\n";
//    system("pause");
    return 0;
}
