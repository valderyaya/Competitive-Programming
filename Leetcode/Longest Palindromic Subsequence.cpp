class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001];
        for(int i=0,j=s.size();i<j;++i){
            dp[i][i]=1;
            for(int j=i-1;j>=0;--j){
                dp[j][i]=0;
                if(i-j>1) dp[j][i]=max(dp[j+1][i-1]+(s[j]==s[i]?2:0), max(dp[j][i-1],dp[j+1][i]));
                else dp[j][i] = s[i]==s[j]?2:1;
            }
        }
        return dp[0][s.size()-1];
    }
};
