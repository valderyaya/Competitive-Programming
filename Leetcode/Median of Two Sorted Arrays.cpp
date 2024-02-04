class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size(),s=n+m,mid=(s+1)/2,i=0,j=0;
        double ans;
        while(i<n||j<m){
            --mid;
            if(i>=n||(j<m&&a[i]>b[j])){
                if(mid==0){
                    ans=b[j];
                    if(s%2==0){
                        ++j;
                        if(i>=n||(j<m&&a[i]>b[j])) ans=(ans+b[j])/2;
                        else ans=(ans+a[i])/2;
                    }
                    break;
                }
                ++j;
            }else{
                if(mid==0){
                    ans=a[i];
                    if(s%2==0){
                        ++i;
                        if(i>=n||(j<m&&a[i]>b[j])) ans=(ans+b[j])/2;
                        else ans=(ans+a[i])/2;
                    }
                    break;
                }
                ++i;
            }
        }
        return ans;
    }
};
