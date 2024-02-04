struct Solution {
    unordered_map<int,int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            if(mp.count(target-nums[i])){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
