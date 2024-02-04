class Solution {
public:
    int f[100005],mx=0,mn=1e9,ret=0,pre[100005];
    int maxProfit(vector<int>& v) {
        for(int i=0;i<v.size();++i){
            f[i]=max(0,v[i]-mn);
            mn=min(mn,v[i]);
            pre[i]=max(i?pre[i-1]:0,f[i]);
        }
        mx=0, ret=pre[v.size()-1];
        for(int i=v.size()-1;i;--i){
            ret=max(ret,pre[i-1]+mx-v[i]);
            mx=max(mx,v[i]);
        }
        return ret;
    }
};
