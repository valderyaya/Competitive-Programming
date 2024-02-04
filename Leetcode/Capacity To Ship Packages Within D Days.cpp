class Solution {
public:
    bool ck(int k, vector<int> &v, int cnt){
        int c=1,sum=0;
        for(int &i:v){
            if(sum+i>k){
                ++c;
                sum=i;
            }else sum+=i;
        }
        return c<=cnt ;
    }
    int shipWithinDays(vector<int>& v, int days) {
        int l=0,r=0,m;
        for(int &i:v){
            l=max(l,i);
            r+=i;
        }
        while(l<r){
            m=(l+r)>>1;
            if(ck(m, v, days)) r=m;
            else l=m+1;
        }
        return l;
    }
};
