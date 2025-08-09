class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;
    double dfs(int x, int y){
        if(x <= 0 && y <= 0) return 0.5;
        if(x <= 0) return 1;
        if(y <= 0) return 0;
        if(dp[x][y]) return dp[x][y];
        return dp[x][y] = 0.25 * (dfs(x - 4, y) + dfs(x - 3, y - 1) + dfs(x - 2, y - 2) + dfs(x - 1, y - 3));
    }
    double soupServings(int n) {
        if(n > 5000) return 1.0;
        return dfs((n + 24) / 25, (n + 24) / 25);
    }
};
