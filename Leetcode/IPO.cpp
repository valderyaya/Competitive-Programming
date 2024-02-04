class Solution {
public:
    int idx;
    vector<pair<int,int>> v;
    priority_queue<int,vector<int>> pq; 
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        for(int i=0;i<profits.size();++i)
            v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());
        while(k--){
            while(idx<profits.size() && v[idx].first <= w)
                pq.push(v[idx++].second);
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }else break;
        }
        return w;
    }
};
