class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m) return 0;
        unordered_map<char,int> mp1,mp2;
        for(auto &i:s1) mp1[i]++;
        for(int i=0;i<m;++i){
            mp2[s2[i]]++;
            if(i>=n){
                if(--mp2[s2[i-n]]==0) mp2.erase(s2[i-n]);
            }
            if(mp1==mp2) return 1;
        }
        return 0;
    }
};
