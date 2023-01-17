#include<bits/stdc++.h>
#pragma GCC optimze("unroll-loops, no-stack-protector, Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll N = 2e5 + 5;
const ll MOD = 1e9+7;
const ld pi = acos(-1);
const ll INF = (1LL<<60);
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lower_bound
#define setp setprecision
#define SZ(_a) (ll)_a.size()
 
ll n, color[N], ans[N];
vector<ll> v[N];
set<ll>* u[N];
 
set<ll>* mg(set<ll> *A, set<ll> *B) {
    if (SZ((*A)) > SZ((*B))) swap(A, B);
    for (ll i : (*A)) (*B).insert(i);
    return B;
}
 
void DFS(ll nd, ll pa) {
    u[nd] = new set<ll>;
    (*u[nd]).insert(color[nd]);
    for (ll i : v[nd]) {
        if (i == pa) continue;
        DFS(i, nd);
        u[nd] = mg(u[nd], u[i]);
    }
    ans[nd] = SZ((*u[nd]));
}
 
int main (){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (ll i = 1;i <= n; ++i) {
        cin >> color[i];
    }
    for (ll i = 0, x, y;i < n-1; ++i) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    DFS(1, 0);
    for (ll i = 1;i <= n; ++i) {
        cout << ans[i] << " \n"[i==n];
    }
    return 0;
}
