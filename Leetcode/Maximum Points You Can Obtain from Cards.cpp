class Solution {
public:
    long long ans,sum[100005],n;
    int maxScore(vector<int>& cardPoints, int k) {
        sum[0]=0; n=cardPoints.size();
        for(int i=0;i<n;++i) sum[i+1]=sum[i]+cardPoints[i];
        for(int i=0;i<=k;++i)
            ans=max(ans,sum[i]+sum[n]-sum[n-(k-i)]);
        return ans;
    }
};
