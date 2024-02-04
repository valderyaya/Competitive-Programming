class Solution {
public:
    #define F first
    #define S second
    #define pii pair<int,int>
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    unordered_map<int,int> mp;
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<int> ret;
        for(auto &i:v) mp[i]++;
        for(auto &i:mp){
            pq.emplace(make_pair(i.S, i.F));
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) ret.emplace_back(pq.top().S), pq.pop();
        return ret;
    }
};
