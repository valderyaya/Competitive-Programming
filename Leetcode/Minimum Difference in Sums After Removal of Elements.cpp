class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        ll n=nums.size()/3, l=0,r=0,L,R,ans=1e18;
        priority_queue<ll,vector<ll>> mx;
        priority_queue<ll,vector<ll>,greater<ll>> mn;
        for(int i=0;i<n;++i) {
            l+=nums[i], mx.emplace(nums[i]);
            r+=nums[i+2*n], mn.emplace(nums[i+2*n]);
        }
        ans=min(ans,l-r);
        L=l, R=r;
        vector<ll> fl(n), fr(n);
        for(int i=n;i<2*n;++i){
            if(mx.top() > nums[i]){
                l-=mx.top();
                mx.pop();
                mx.push(nums[i]);
                l+=nums[i];
            }
            fl[i-n]=l;
        }
        for(int i=2*n-1;i>=n;--i){
            if(mn.top() < nums[i]){
                r-=mn.top();
                mn.pop();
                mn.push(nums[i]);
                r+=nums[i];
            }
            fr[i-n]=r;
        }
        for(int i=0;i+1<n;++i) ans=min(ans,fl[i]-fr[i+1]);
        ans=min({ans,L-fr[0],fl[n-1]-R});
        return ans;
    }
};
