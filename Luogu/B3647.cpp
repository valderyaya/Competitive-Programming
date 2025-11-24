#include<bits/stdc++.h>
using namespace std;

int n, m, f[101][101];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j) f[i][j] = numeric_limits<int>::max() / 4;
    for(int u, v, w; m--;){
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = min(f[v][u], w);
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cout << (f[i][j] == INT_MAX ? 0 : f[i][j]) << " \n"[j == n];
    return 0;
}
