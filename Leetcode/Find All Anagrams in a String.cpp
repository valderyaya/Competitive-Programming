class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26,0),v2(26,0),ret;
        int n=s.size(), m=p.size();
        for(int i=0;i<m;++i) ++v2[p[i]-'a'];
        for(int i=0;i<n;++i){
            ++v1[s[i]-'a'];
            if(i>=m) --v1[s[i-m]-'a'];
            if(v1==v2) ret.push_back(i-m+1);
        }
        return ret;
    }
};
