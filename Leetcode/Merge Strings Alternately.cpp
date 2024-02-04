class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int j=word1.size(), k=word2.size();
        string ret="";
        for(int i=0;i<max(j,k);++i){
            if(i<j) ret+=word1[i];
            if(i<k) ret+=word2[i];
        }
        return ret;
    }
};
