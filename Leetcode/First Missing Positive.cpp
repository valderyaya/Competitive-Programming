class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0, n=nums.size();
        while(i<n){
            if(nums[i]<1||nums[i]>n) ++i;
            else{
                swap(nums[i],nums[nums[i]-1]);
                if(nums[i]==i+1||(nums[i]>0&&nums[i]<=n&&nums[i]==nums[nums[i]-1])) ++i;
            }
        }
        for(int i=0;i<n;++i) if(nums[i]!=i+1) return i+1;
        return n+1;
    }
};
