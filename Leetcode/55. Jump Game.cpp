class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), cur = 0;
        bool ret = true;
        vector<int> diff(n + 1, 0);
        for(int i = 0; i + 1 < nums.size(); ++i){
            diff[i + 1] += nums[i];
            diff[min(i + nums[i] + 1, n)] -= nums[i];
        }
        for(int i = 1; i < n; ++i){
            cur += diff[i];
            if(cur == 0){
                ret = false;
                break;
            }
        }
        return ret;
    }
};
