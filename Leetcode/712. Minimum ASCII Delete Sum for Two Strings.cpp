class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0, cur = 0, n = s1.size(), m = s2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for(auto &i: s1) sum += i;
        for(auto &i: s2) sum += i;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s1[i] == s2[j]){
                    dp[cur ^ 1][j + 1] = dp[cur][j] + s1[i];
                }else{
                    dp[cur ^ 1][j + 1] = max(dp[cur][j + 1], dp[cur ^ 1][j]);
                }
            }
            cur ^= 1;
        }
        // cout << sum << ' ' << dp[cur][m] << ' ' << dp[cur ^ 1][m] << endl;
        return sum - 2 * dp[cur][m];
    }
};
