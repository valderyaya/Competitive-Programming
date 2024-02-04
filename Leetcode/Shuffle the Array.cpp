class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for(int i=0;i<n;++i) v.emplace_back(nums[i]),v.emplace_back(nums[i+n]);
        return v;
    }
};
