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

const int z=100005;
struct edge{int to,nxt;}e[z<<1];
int cnt=0,n,m,fa[z],top[z],h[z],dep[z],dfn[z],tot=0,son[z],sz[z],sum[z<<2],laz[z<<2];

void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}

void dfs(int x){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs(v);
        sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}

void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    if(son[x]) dfs2(son[x],t);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x]) dfs2(v,v);
    }
}

void down(int l,int r,int rt){
    int mid=l+r>>1;
    laz[rt<<1]=laz[rt<<1|1]=laz[rt];
    sum[rt<<1]=laz[rt]*(mid-l+1);
    sum[rt<<1|1]=laz[rt]*(r-mid);
    laz[rt]=-1;
}

void modify(int l,int r,int ql,int qr,int rt,int tag){
    if(ql<=l&&r<=qr)return sum[rt]=(r-l+1)*tag,laz[rt]=tag,void();
    int mid=l+r>>1;
    if(~laz[rt]) down(l,r,rt);
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,tag);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,tag);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void install(int x){
    while(top[x]!=1){
        modify(1,n,dfn[top[x]],dfn[x],1,1);
        x=fa[top[x]];
    }
    modify(1,n,1,dfn[x],1,1);
}

int main(){Rosario
    cin>>n;
    int x;
    string s;
    REP1(i,2,n) cin>>x,++x,add(i,x),add(x,i);
    dep[1]=fa[1]=1;
    dfs(1);dfs2(1,1);
    cin>>m;
    while(m--){
        cin>>s>>x;++x;
        int tmp=sum[1];
        if(s[0]=='i'){
            install(x);
            cout<<abs(tmp-sum[1])<<"\n";
        }else{
            modify(1,n,dfn[x],dfn[x]+sz[x]-1,1,0);
            cout<<abs(tmp-sum[1])<<"\n";
        }
    }
//    system("pause");
    return 0;
}
