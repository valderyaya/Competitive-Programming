class Solution {
public:
    int maxRotateFunction(vector<int>& v) {
        int sum=0,val=0,n=v.size(),mx=0;
        for(int i=0;i<n;++i) val+=i*v[i], sum+=v[i];
        mx=val;
        for(int i=0;i<n;++i){
            val = val - sum + n*v[i];
            mx=max(mx,val);
        }
        return mx;
    }
};

