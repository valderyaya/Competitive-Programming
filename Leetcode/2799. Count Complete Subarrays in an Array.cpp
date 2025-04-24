class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k = unordered_set<int>(nums.begin(), nums.end()).size(), cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0, j = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
            while(mp.size() == k){
                cnt += nums.size() - i;
                if(--mp[nums[j]] == 0) mp.erase(nums[j]);
                ++j;
            }
        }
        return cnt;
    }
};
