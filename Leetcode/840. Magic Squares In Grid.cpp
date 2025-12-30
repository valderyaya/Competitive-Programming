class Solution {
public:
    bool check(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        int cnt[10] = {};
        unordered_set<int> s;
        for(int i = x1; i <= x2; ++i){
            int sum = 0;
            for(int j = y1; j <= y2; ++j){
                if(grid[i][j] > 9 || grid[i][j] == 0) return false;
                if(++cnt[grid[i][j]] > 1) return false;
                sum += grid[i][j];
            }
            s.insert(sum);
        }
        s.insert(grid[x1][y1] + grid[x1 + 1][y1] + grid[x1 + 2][y1]);
        s.insert(grid[x1][y1 + 1] + grid[x1 + 1][y1 + 1] + grid[x1 + 2][y1 + 1]);
        s.insert(grid[x1][y2] + grid[x1 + 1][y2] + grid[x1 + 2][y2]);
        s.insert(grid[x1][y1] + grid[x1 + 1][y1 + 1] + grid[x2][y2]);
        s.insert(grid[x1][y2] + grid[x1 + 1][y1 + 1] + grid[x2][y1]);
        return (int)s.size() == 1;        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i + 2 < grid.size(); ++i){
            for(int j = 0; j + 2 < grid[i].size(); ++j){
                // cout << i << ' ' << j << ' ' << i + 2 << ' ' << j + 2 << endl;
                if(check(grid, i, j, i + 2, j + 2))
                    ++ans;
            }
        }
        return ans;
    }
};

// 4 7 8
// 9 5 1
// 2 3 6
