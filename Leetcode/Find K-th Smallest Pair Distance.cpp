class Solution {
public:
    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=0,r=v.back()-v[0];
        while(l<r){
            int mid=(l+r)>>1,cnt=0, j=0;
            for(int i=0;i<v.size();++i){
                while(j<v.size()&& v[i]-v[j]>mid) ++j;
                cnt+=i-j;
            }
            if(cnt<k) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
