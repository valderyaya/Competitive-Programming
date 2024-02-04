class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int mx=0, ans=arr[0], cnt[100001]={};
        for(auto &i:arr)
            if(++cnt[i] > mx) mx = cnt[i], ans = i;
        return ans;
    }
};
