class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,cnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1) ++cnt;
            else{
                mx=max(mx,cnt);
                cnt=0;
            }
        }
        return max(cnt,mx);
    }
};
