class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int dp[205][205]={}, n=d.size(), m=d[0].size();
        for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) dp[i][j]=INT_MAX;
        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i=n-1;~i;--i)
            for(int j=m-1;~j;--j){
                int x=min(dp[i][j+1],dp[i+1][j]) - d[i][j];
                dp[i][j] = x <= 0 ? 1 : x;
            }
        return dp[0][0];
    }
};
