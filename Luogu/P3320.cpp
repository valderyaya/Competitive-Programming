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

const int z = 1e5+5;
int dfn[z], cnt, lca[z][18], dep[z], n, m, id[z];
vector<pii> v[z];
bitset<z> vis;
ll ans, dis[z];
set<int> s;
set<int>::iterator it;
void dfs(int x){
    dfn[x] = ++cnt;
    id[cnt] = x;
    for(auto &[u, w] :v[x]){
        if(dep[u]) continue;
        lca[u][0] = x, dep[u] = dep[x] + 1;
        dis[u] = dis[x] + w;
        dfs(u);
    }
}
int LCA(int x,int y){
    if(dep[x] > dep[y]) swap(x,y);
    for(int d = dep[y]-dep[x], k=0; d; d>>=1, ++k)
        if(d & 1) y = lca[y][k];
    if(x==y) return x;
    for(int i = 17;~i;--i)
        if(lca[x][i] != lca[y][i])
            x=lca[x][i], y=lca[y][i];
    return lca[x][0];
}
void build(){
    for(int j=1;j<18;++j)
        for(int i = 1; i <= n; ++i)
            lca[i][j] = lca[lca[i][j-1]][j-1];
}
ll dist(int x, int y){return dis[x] + dis[y] - 2*dis[LCA(x,y)];}
ll mdf(int x){
    x = dfn[x];
    if(!vis[id[x]]) s.insert(x);
    int l = id[((it = s.lower_bound(x)) == s.begin() ? *--s.end() : *--it)];
    int r = id[((it = s.upper_bound(x)) == s.end() ? *s.begin() : *it)];
    if(vis[id[x]]) s.erase(x);
    x = id[x];
    ll d = dist(l, x) + dist(x, r) - dist(l, r);
    if(!vis[x]) vis[x]=1, ans+=d;
    else vis[x]=0, ans-=d;
    //cout<<": "<<s.size()<<endl;
    return ans;
}
signed main(){StarBurstStream
    cin >> n >> m;
    for(int x, y ,w, i=1; i < n; ++i){
        cin>>x>>y>>w;
        v[x].em(y,w);
        v[y].em(x,w);
    }
    dfs(dep[1] = lca[1][0] = 1);
    build();
    for(int x;m--;){
        cin >> x;
        cout<<mdf(x)<<"\n";
    }
    return 0;
}
