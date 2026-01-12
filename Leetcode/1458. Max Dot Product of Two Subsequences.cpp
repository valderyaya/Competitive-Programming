class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size(), m = nums2.size();
        vector<int> dp(m + 1, -1e9);
        for(int i = 0, last; i < n; ++i){
            last = -1e9;
            for(int j = 0, prod, temp; j < m; ++j){
                prod = nums1[i] * nums2[j];
                temp = dp[j + 1];
                dp[j + 1] = max({dp[j], temp, prod, prod + last});
                last = temp;
            }
        }
        return dp[m];
    }
};
