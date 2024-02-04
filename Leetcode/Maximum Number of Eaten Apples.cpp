class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ret=0,n=days.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;++i){
            while(!pq.empty() && pq.top().first<i+1) pq.pop(); 
            if(apples[i]) pq.push({i+days[i],apples[i]});
            if(!pq.empty()){
                ++ret;
                auto x=pq.top();
                pq.pop();
                if(--x.second) pq.emplace(x);    
            }
        }
        for(int i=n;!pq.empty();++i){
            while(!pq.empty() && pq.top().first<i+1) pq.pop();
            if(!pq.empty()){
                ++ret;
                auto x=pq.top();
                pq.pop();
                if(--x.second) pq.emplace(x); 
            }
        }
        return ret;
    }
};
