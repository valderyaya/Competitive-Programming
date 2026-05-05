class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), ans;
        vector f(m + 1, vector<int>(k + 2, INT_MIN));
        fill(f[1].begin() + 1, f[1].end(), 0);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                for(int l = k; l >= 0; --l){
                    int new_k = l - (grid[i][j] > 0);
                    f[j + 1][l + 1] = max(f[j + 1][new_k + 1], f[j][new_k + 1]) + grid[i][j];
                }

        ans = f[m][k + 1];
        return ans < 0 ? -1 : ans;
    }
};
