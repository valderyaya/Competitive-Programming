#include<bits/stdc++.h>
#pragma GCC optimze("unroll-loops, no-stack-protector, Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll N = 2e5 + 5;
const ll K = sqrt(N);
const ll MOD = 1e9+7;
const ld pi = acos(-1);
const ll INF = (1LL<<60);
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lwb lower_bound
#define setp setprecision
#define SZ(_a) (ll)_a.size()
 
ll pos = 0, in[N], out[N];
 
ll n, color[N], arr[N], ans[N], rk[N];
vector<ll> v[N], lis, query;
ll cnt = 0, m[N];
 
void DFS(ll nd, ll pa) {
    in[nd] = pos++;
    for (ll i : v[nd]) {
        if (i == pa) continue;
        DFS(i, nd);
    }
    out[nd] = pos;
}
 
void add(ll val) {
    if (m[val] == 0) ++cnt;
    ++m[val];
}
 
void sub(ll val) {
    if (m[val] == 1) --cnt;
    --m[val];
}
 
int main (){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (ll i = 1;i <= n; ++i) {
        cin >> color[i];
        lis.pb(color[i]);
    }
    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());
    for (ll i = 1;i <= n; ++i) {
        color[i] = lwb(lis.begin(), lis.end(), color[i]) -lis.begin();
    }
    for (ll i = 0, x, y;i < n-1; ++i) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    DFS(1, 0);
    for (ll i = 1;i <= n; ++i) {
        arr[in[i]] = color[i];
    }
    for (ll i = 1;i <= n; ++i) {
        rk[i] = in[i]/K;
        query.pb(i);
    }
    sort(query.begin(), query.end(), [&](ll A, ll B) {
        if (rk[A] != rk[B]) {
            return rk[A] < rk[B];
        }
        return (rk[A]&1 ? out[A] > out[B] : out[A] < out[B]);
    });
    ll lpos = 0, rpos = -1;
    for (auto i : query) {
        ll ql = in[i], qr = out[i]-1;
        while (lpos > ql) add(arr[--lpos]);
        while (rpos < qr) add(arr[++rpos]);
        while (lpos < ql) sub(arr[lpos++]);
        while (rpos > qr) sub(arr[rpos--]);
        ans[i] = cnt;
    }
    for (ll i = 1;i <= n; ++i) {
        cout << ans[i] << " \n"[i==n];
    }
    return 0;
}
