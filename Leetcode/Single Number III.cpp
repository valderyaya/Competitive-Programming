class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(auto &i:nums) x^=i;
        vector<int> v={0, 0};
        x = x & -x;
        for(auto &i:nums)
            if((i & x) == 0) v[0]^=i;
            else v[1]^=i;
        return v; 
    }
};
