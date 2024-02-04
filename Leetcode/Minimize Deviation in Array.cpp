class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       int ret=1e9,mn=1e9;
       priority_queue<int> pq;
       for(auto &i:nums){
           if(i&1) mn=min(mn,i*2), pq.push(i*2);
           else mn=min(mn,i), pq.push(i);
       } 
       while(!pq.empty()){
           int x=pq.top(); pq.pop();
           ret=min(ret,x-mn);
           if(x&1) break;
           mn=min(mn,x/2);
           pq.push(x/2);
       }
       return ret;
    }
};
