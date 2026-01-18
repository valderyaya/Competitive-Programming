class Solution {
public:
    bool check(int x, int y, int xx, int yy, vector<vector<int>>& grid, vector<vector<int>>& row_sum, vector<vector<int>>& col_sum){
        int tmp = row_sum[x][yy] - (y ? row_sum[x][y - 1] : 0), tmp2 = 0;
        for(int i = x + 1; i <= xx; ++i)
            if(tmp != (row_sum[i][yy] - (y ? row_sum[i][y - 1] : 0)))
                return false;

        for(int i = y + 1; i <= yy; ++i)
            if(tmp != (col_sum[xx][i] - (x ? col_sum[x - 1][i] : 0)))
                return false;
        
        for(int i = x, j = y; i <= xx && j <= yy; ++i, ++j)
                tmp2 += grid[i][j];
        if(tmp != tmp2) return false;
        
        tmp2 = 0;
        for(int i = xx, j = y; i >= x && j <= yy; --i, ++j)
                tmp2 += grid[i][j];

        return tmp == tmp2;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> row_sum(grid), col_sum(grid);
        for(int i = 0; i < n; ++i)
            for(int j = 1; j < m; ++j) 
                row_sum[i][j] += row_sum[i][j - 1];
        
        for(int j = 0; j < m; ++j)
            for(int i = 1; i < n; ++i)
                col_sum[i][j] += col_sum[i - 1][j];
            
        for(int length = min(n, m); length > 1; --length)
            for(int i = 0; i + length - 1 < n; ++i)
                for(int j = 0; j + length - 1 < m; ++j)
                    if(check(i, j, i + length - 1, j + length - 1, grid, row_sum, col_sum))
                        return length;
        
        return 1;
    }
};
