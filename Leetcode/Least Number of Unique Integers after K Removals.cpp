class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int> >pq;
        for(auto &i:v) ++mp[i];
        for(auto &i:mp) pq.emplace(i.second);
        while(k>0){
            if(pq.top() <= k){
                k -= pq.top();
                pq.pop();
            }else{
                k = 0;
            }
        }
        return pq.size();
    }
};
