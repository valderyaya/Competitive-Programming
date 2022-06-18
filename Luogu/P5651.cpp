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

const int z=1e5+1;
struct edge{int to,w,nxt;}e[z<<1];
int n,cnt=0,m,q,dis[z],h[z],pa[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,w,h[u]};
    h[u]=cnt;
}
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void dfs(int x,int p){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dis[v]=dis[x]^e[i].w;
        dfs(v,x);
    }
}
int main(){Rosario
    cin>>n>>m>>q;
    int x,y,w;
    REP1(i,1,n) pa[i]=i;
    while(m--) {cin>>x>>y>>w;
        if(fin(x)!=fin(y)) pa[fin(x)]=fin(y),add(x,y,w),add(y,x,w);
    }
    dfs(1,0);
    while(q--) cin>>x>>y,cout<<(dis[x]^dis[y])<<"\n";
    return 0;
}
