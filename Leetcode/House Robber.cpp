class Solution {
public:
    int rob(vector<int>& v) {
        int dp[101]={};
        for(int i = 0; i < v.size(); ++i)
            dp[i] = max((i > 0 ? dp[i - 1] : 0), (i > 1 ? dp[i - 2] : 0) + v[i]);
        return dp[v.size() - 1];
    }
};
