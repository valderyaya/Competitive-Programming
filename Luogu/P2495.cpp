#include<bits/stdc++.h>
using namespace std;
#define StarBrustStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ALL(x) x.begin(),x.end()
#define ll long long 

const int maxn = 5e5+5;
struct qwq{
    int v, nxt, w;
}e[maxn << 1];
struct edge{
    int v, nxt;
}e2[maxn << 1];
int n, m, h[maxn], cnt, cnt2, h2[maxn], dep[maxn], dfn[maxn], tme, lca[19][maxn], stk[maxn], ind;
ll DP[maxn];
vector<int> v;
bitset<maxn> crt;
bool cmp(int x, int y){
    return dfn[x] < dfn[y];
}

void add(int u, int v, int w){
    e[++cnt] = qwq{v, h[u], w};
    h[u] = cnt;
}

void add2(int u, int v){
    e2[++cnt2] = edge{v, h2[u]};
    h2[u] = cnt2;
}

void dfs(int x){
    dfn[x] = ++tme;
    for(int v, i = h[x]; i; i = e[i].nxt){
        v = e[i].v;
        if(dfn[v]) continue;
        lca[0][v] = x;
        dep[v] = dep[x] + 1;
        DP[v] = min(DP[x], (ll)e[i].w);
        dfs(v);
    }
}

void build_lca(){
    for(int i = 1; i <= 18; ++i)
        for(int j = 1; j <= n; ++j)
            lca[i][j] = lca[i-1][lca[i-1][j]];
}

int LCA(int x, int y){
    if(dep[x] > dep[y]) swap(x,y);
    for(int d = dep[y] - dep[x], i = 0; d; d>>=1, ++i)
        if(d & 1) y = lca[i][y];
    if(x == y) return x;
    for(int i = 18; ~i; --i)
        if(lca[i][x] != lca[i][y])
            x = lca[i][x], y = lca[i][y];
    return lca[0][x];
}

ll dp(int x){
    ll sum=0, ret;
    for(int i = h2[x]; i; i = e2[i].nxt)
        sum += dp(e2[i].v);
	ret = crt[x] ? DP[x] : min(DP[x], sum);
	h2[x] = crt[x] = 0;
    return ret;
}

void build_edge(){
    sort(ALL(v), cmp);
    cnt2 = 0;
    stk[ind = 1] = 1;
    for(auto &i : v)
        if(i != 1){
            int l = LCA(stk[ind], i);
            if(l != stk[ind]){
                while(dfn[l] < dfn[stk[ind - 1]])
                    add2(stk[ind-1], stk[ind]), --ind;
                if(dfn[l] != dfn[stk[ind-1]])
                    add2(l, stk[ind]), stk[ind]=l;
				else add2(l, stk[ind--]);
			}
            stk[++ind] = i;
        }
    for(int i = 1; i < ind; ++i)
        add2(stk[i], stk[i+1]);
}
signed main(){StarBrustStream
    cin >> n;
    for(int x, y, w, i = 2; i <= n; ++i){
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
        DP[i] = 1e18;
    }
    DP[1] = 1e18;
    dep[1] = lca[0][1] = 1;
    dfs(1);
    build_lca();
    cin >> m;
    for(int k; m--;){
        cin >> k;
        v.resize(k);
        for(int i = 0; i < k; ++i)
            cin >> v[i], crt[v[i]] = 1;
        build_edge();
        cout << dp(1) << "\n";
    }
}
