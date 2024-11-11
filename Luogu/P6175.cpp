#include<bits/stdc++.h>
using namespace std;

const int inf = 1e8;
int n, m, dis[101][101], a[101][101], ans = inf;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dis[i][j] = inf;
    
    for(int x, y, w; m--;){
        cin >> x >> y >> w;
        dis[x][y] = dis[y][x] = min(dis[x][y], w);
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = dis[i][j];

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i < k; ++i)
            for(int j = i + 1; j < k; ++j)
                ans = min(ans, dis[i][j] + a[i][k] + a[k][j]);
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }

    if(ans == inf) cout << "No solution.\n";
    else cout << ans << "\n";
}
