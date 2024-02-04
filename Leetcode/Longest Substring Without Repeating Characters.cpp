class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128]={},l=0,r=0,mx=0;
        for(;r<s.size();++r){
            cnt[s[r]]++;
            while(cnt[s[r]]>1) cnt[s[l++]]--;
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};
