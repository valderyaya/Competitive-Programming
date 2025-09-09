class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = (i == 2 ? 0 : dp[i - 1]);
            if(i - delay > 0)
                dp[i] = (dp[i] + dp[i - delay]) % mod;
            if(i - forget > 0)
                dp[i] = (dp[i] - dp[i - forget] + mod) % mod;
        }
        long long ret = 0;
        for(int i = n - forget + 1; i <= n; ++i)
            ret = (ret + dp[i]) % mod;
        return ret;
    }
};
