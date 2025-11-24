class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ans;
        for(auto &digit : nums){
            cur = (cur * 2 + digit) % 5;
            ans.emplace_back(cur ? false : true);
        }
        return ans;
    }
};
