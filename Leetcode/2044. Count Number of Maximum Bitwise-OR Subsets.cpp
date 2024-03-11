class Solution {
public:
    int dp[65539];
    int countMaxOrSubsets(vector<int>& v) {
        int ans = -1, cnt = 0, n = v.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) mp[1<<i] = i;
        for(int prv, lb, mask = 1; mask < (1 << n); ++mask){
            lb = mask & (-mask);
            prv = mask - lb;
            dp[mask] = dp[prv] | v[mp[lb]];
            if(dp[mask] > ans) ans = dp[mask], cnt = 1;
            else if(dp[mask] == ans) ++cnt;
        }
        return cnt;
    }
};
