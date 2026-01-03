class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1}, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                dis[i][j] = INT_MAX;
        dis[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();
            if(x == n - 1 && y == m - 1) break;
            for(int xx, yy, i = 0; i < 4; ++i){
                xx = x + dx[i], yy = y + dy[i];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m || dis[xx][yy] != INT_MAX)
                    continue;
                if(dis[xx][yy] > dis[x][y] + grid[xx][yy]){
                    dis[xx][yy] = dis[x][y] + grid[xx][yy];
                    if(grid[xx][yy]) dq.push_back({xx, yy});
                    else dq.push_front({xx, yy});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
