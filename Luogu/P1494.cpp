#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int z = 50005;
int n, m, maxn;
int c[z],cnt[z];
ll sum,ans1[z], ans2[z];;
struct query {
  int l, r, id;
  bool operator<(const query &x) const {
    if (l / maxn != x.l / maxn) return l < x.l;
    return (l / maxn) & 1 ? r < x.r : r > x.r;
  }
} a[z];
void add(int i) {
  sum += cnt[i];
  cnt[i]++;
}
void del(int i) {
  cnt[i]--;
  sum -= cnt[i];
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d%d", &n, &m);
  maxn = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
  sort(a, a + m);
  for (int i = 0, l = 1, r = 0; i < m; i++) {
    if (a[i].l == a[i].r) {
      ans1[a[i].id] = 0, ans2[a[i].id] = 1;
      continue;
    }
    while (l < a[i].l) del(c[l++]);
    while (l > a[i].l) add(c[--l]);
    while (r < a[i].r) add(c[++r]);
    while (r > a[i].r) del(c[r--]);
    ans1[a[i].id] = sum;
    ans2[a[i].id] = (long long)(r - l + 1) * (r - l) / 2;
  }
  for (int i = 0; i < m; i++) {
    if (ans1[i] != 0) {
      ll g = gcd(ans1[i], ans2[i]);
      ans1[i] /= g, ans2[i] /= g;
    } else
      ans2[i] = 1;
    printf("%lld/%lld\n", ans1[i], ans2[i]);
  }
  return 0;
}
