class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long res=0;
        for(int i=0,j=0;i<v.size();++i){
            if(v[i]==0){
                long long s=1;
                for(j=i+1;j<v.size()&&v[j]==0;++j) s+=(j-i+1);
                res+=s;
                i=j;
            }
        }
        return res;
    }
};
