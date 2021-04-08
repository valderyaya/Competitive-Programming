#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL inf = (LL)9.22e18;
const int dr[] = {-3, -3, -1, 1, 3, 3, 1, -1};
const int dc[] = {1, -1, -3, -3, -1, 1, 3, 3}; 
const int kr[] = {-1, -1, 0, 0, 1, 1, 0, 0};
const int kc[] = {0, 0, -1, -1, 0, 0, 1, 1};
bool G[105][105];
int vis[105][105]; 
int n, sr, sc, er, ec;
queue<P> Q;
int main() {
    memset(vis, 0, sizeof(vis));
    memset(G, 0, sizeof(G));
    scanf("%d", &n);
    int r, c;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &r, &c);
        G[r][c] = true;
    }
    scanf("%d%d%d%d", &sr, &sc, &er, &ec);
    vis[sr][sc] = 1;
    Q.push(make_pair(sr,sc));
    while(!Q.empty()) {
        r = Q.front().F, c = Q.front().S;
        Q.pop();
        if(r == er && c == ec) {
            printf("%d\n", vis[r][c]-1);
            return 0;
        }
        for(int i = 0; i < 8; i++) {
            int rr = r+dr[i], cc = c+dc[i];
            int br = r+kr[i], bc = c+kc[i];
            if(rr < 0 || rr > 99 || cc < 0 || cc > 99 || vis[rr][cc] || G[br][bc] || G[rr][cc]) continue;
            vis[rr][cc] = vis[r][c]+1;
            Q.push(make_pair(rr,cc));
        }
    }
    puts("impossible");
    return 0;
}
