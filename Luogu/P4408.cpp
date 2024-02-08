//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

#define int ll
const int z=2e5+5;
int dep[z], n, m, mxd, st, ed, dis[z], lca[19][z], ans, diameter;
vector<pll> v[z];
bool flag;
void dfs(int x, int d, int p, bool f){
    if(f) dis[x] = d;
    if(d > mxd) mxd = d, st = x;
    for(auto &i:v[x])
        if(i.F!=p){
            if(f) lca[0][i.F] = x, dep[i.F] = dep[x] + 1;
            dfs(i.F, d+i.S, x, f);
        }
}
void build(){
    for(int i = 1; i < 19; ++i)
        for(int j = 1; j <= n; ++j)
            lca[i][j] = lca[i-1][lca[i-1][j]];
}
int LCA(int x, int y){
    if(dep[x] > dep[y]) swap(x,y);
    for(int k=0, d=dep[y]-dep[x]; d; d>>=1, ++k)
        if(d&1) y = lca[k][y];
    if(x==y) return x;
    for(int i = 18;~i;--i)
        if(lca[i][x]!=lca[i][y])
            x=lca[i][x], y=lca[i][y];
    return lca[0][x];
}
int Dis(int x, int y){
    return dis[x] + dis[y] - 2*dis[LCA(x, y)];
}
signed main(){StarBurstStream
    cin>>n>>m;
    for(int x,y,w,i=1; i<n; ++i){
        cin>>x>>y>>w;
        v[x].em(y,w);
        v[y].em(x,w);
    }
    dfs(1, 0, 1, 1);
    lca[0][1] = 1;
    build();
    ed = st;
    mxd = 0;
    dfs(st, 0, st, 0);
    //REP1(i,1,n) cout<<dis[i]<<' '<<dep[i]<<endl;
    //cout<<dim.size()<<endl;
    diameter = Dis(st, ed);
    for(int i = 1; i <= n; ++i)
        ans = max(ans, diameter + min(Dis(st, i), Dis(ed, i)));
    cout << ans << "\n";
    return 0;
}
