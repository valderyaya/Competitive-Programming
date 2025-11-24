class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for(auto &i : nums){
            vector<int> f = dp;
            for(int j = 0; j < 3; ++j)
                f[(i % 3 + j) % 3] = max(f[(i % 3 + j) % 3], dp[j] + i);
            dp = move(f);
        }
        return dp[0];
    }
};
