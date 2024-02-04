class Solution {
public:
    int dp[205][205];
    int minPathSum(vector<vector<int>>& a){
        int n=a.size(),m=a[0].size();
        for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) dp[i][j]=1e9;
        dp[0][1]=dp[1][0]=0;
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i-1][j-1];
        return dp[n][m];
    }
};
