class Solution {
public:
    int jump(vector<int>& v) {
        int dp[10001],n=v.size();
        for(int i=1;i<n;++i) dp[i]=1e9;
        dp[0]=0;
        for(int i=0;i<n;++i)
            for(int j=1;i+j<n&&j<=v[i];++j) dp[i+j]=min(dp[i+j],dp[i]+1);
        return dp[n-1];
    }
};
