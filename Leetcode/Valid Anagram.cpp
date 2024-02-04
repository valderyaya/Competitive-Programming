class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26),b(26);
        for(auto &i:s) a[i-'a']++;
        for(auto &i:t) b[i-'a']++;
        return a==b;
    }
};
