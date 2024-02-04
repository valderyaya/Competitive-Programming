class Solution {
public:
    int singleNonDuplicate(vector<int>& v){
        int l=0,r=v.size()-1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(v[mid]==v[mid+1]){
                if((mid)%2==0) l=mid+2;
                else r=mid-1;
            }else{
                if((mid+1)%2==0) l=mid+1;
                else r=mid;
            }
        }
        return v[l];
    }
};
