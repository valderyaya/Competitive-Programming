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

#define int ll
const int z=1e3+5,inf=2147483647000000;
int in[z],n,m,out[z],lca[z][19],dfn=0,pa[z],now=0;
vector<pll> v[z];
ll mx[z][19],sec[z][19],sum=0;
struct  qq{
    ll a,b,c;
    bool operator<(const qq &x){return c<x.c;}
}q[570005];
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
void dfs(int x,int p){
    in[x]=++dfn;
    for(auto &i:v[x]){
        if(i.F==p) continue;
        lca[i.F][0]=x,mx[i.F][0]=i.S;
        sec[i.F][0]=-inf; dfs(i.F,x);
    }out[x]=++dfn;
}
void build(){
    for(int j=1;j<19;++j)
        for(int i=1;i<=n;++i){
            lca[i][j]=lca[lca[i][j-1]][j-1];
            mx[i][j]=max(mx[i][j-1],mx[lca[i][j-1]][j-1]);
            sec[i][j]=max(sec[i][j-1],sec[lca[i][j-1]][j-1]);
            if(mx[i][j]>mx[lca[i][j-1]][j-1]) sec[i][j]=max(sec[i][j],mx[lca[i][j-1]][j-1]);
            else if(mx[i][j]<mx[lca[i][j-1]][j-1]) sec[i][j]=max(sec[i][j],mx[i][j]);
        }
}
bool is(int a,int b){return in[a]<=in[b]&&out[a]>=out[b];}
int LCA(int a,int b){
    if(is(a,b)) return a;
    if(is(b,a)) return b;
    for(int i=18;~i;--i) if(!is(lca[a][i],b)) a=lca[a][i];
    return lca[a][0];
}
ll que(int x,int y,ll w){
    if(x==y) return 0;
    if(is(x,y)) x^=y^=x^=y;
    ll res=-inf;
    for(int i=18;~i;--i) if(!is(lca[x][i],y)){
        if(mx[x][i]!=w) res=max(res,mx[x][i]);
        else res=max(res,sec[x][i]);
        x=lca[x][i];
    }return max(res,(mx[x][0]==w?sec[x][0]:mx[x][0]));
}
bitset<570005> vis;
void run(){
    sort(q,q+m);
    REP(i,m){
        int x=fin(q[i].a),y=fin(q[i].b);
        if(x==y) continue;
        vis[i]=1; pa[x]=y; sum+=q[i].c; now++;
        v[q[i].a].em(mkp(q[i].b,q[i].c));
        v[q[i].b].em(mkp(q[i].a,q[i].c));
    }
    lca[1][0]=1;mx[1][0]=0;sec[1][0]=-inf; dfs(1,1); build();
}
 main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) pa[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    run();
    if(now!=n-1) return cout<<"-1 -1",0;
    ll ans=inf;
    REP(i,m) if(!vis[i]){
        int x=LCA(q[i].a,q[i].b);
        ll ss=max(que(q[i].a,x,q[i].c),que(q[i].b,x,q[i].c));
        ans=min(ans,sum-ss+q[i].c);
    }
    cout<<sum<<' '<<(ans==inf?-1:ans)<<"\n";
    return 0;
}
