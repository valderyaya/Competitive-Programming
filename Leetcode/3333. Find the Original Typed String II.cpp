class Solution {
public:
    int possibleStringCount(string word, int k) {
        if(word.size() < k) return 0;
        const long long mod = 1e9 + 7;
        vector<int> cnt;
        long long ans = 1;
        for(int i = 0, c = 0; i < word.size(); ++i){
            ++c;
            if(i == word.size() - 1 || word[i] != word[i+1]){
                if(c > 1){
                    ans = ans * c % mod;
                    if(k > 0)
                        cnt.emplace_back(c - 1);
                }
                --k;
                c = 0;
            }
        }
        if(k <= 0) return ans;
        vector<int> dp(k, 1);
        for(auto &x : cnt){
            for(int i = 1; i < k; ++i)
                dp[i] = (dp[i] + dp[i - 1]) % mod;

            for(int i = k - 1; i > x; --i)
                dp[i] = (dp[i] - dp[i - x - 1]) % mod ;
        }
        return (ans - dp[k - 1] + mod) % mod;
    }
};
