class Solution {
public:
    string longestPalindrome(string s) {
        int len=1,pos=0,n=(int)s.size();
        for(int i=0,j,k;i<n;++i){
            if(i-1>=0 && i+1<n && s[i-1]==s[i+1])
                for(j=i-1, k=i+1; j>=0 && k<n; ++k, --j){
                    if(s[j]!=s[k]) break;
                    if(k-j+1>len) pos=j,len=k-j+1;
                }
            if(i+1<n && s[i]==s[i+1])
                for(j=i,k=i+1;j>=0&&k<n;++k,--j){
                    if(s[k]!=s[j]) break;
                    if(k-j+1>len) pos=j,len=k-j+1;
                }
        }
        return s.substr(pos,len);
    }
};
