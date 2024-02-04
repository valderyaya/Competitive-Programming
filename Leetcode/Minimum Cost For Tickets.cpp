class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[370]={},n=days.size(),m=min({costs[0],costs[1],costs[2]});
        for(int i=0;i<n;++i){
            dp[i]=(i?dp[i-1]+m:m);
            for(int j=i-1;j>=0;--j){
                if(days[i]-days[j]+1<=7) dp[i]=min(dp[i],(j==0?0:dp[j-1])+costs[1]);
                if(days[i]-days[j]+1<=30){
                    dp[i]=min(dp[i],(j==0?0:dp[j-1])+costs[2]);
                }else break;
            } 
        }
        return dp[n-1];
    }
};
