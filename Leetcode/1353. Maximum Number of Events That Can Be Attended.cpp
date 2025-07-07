class Solution {
public:
    vector<int> fa;
    int find_parent(int x){
        return x == fa[x] ? x : fa[x] = find_parent(fa[x]);
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
        int maxd = 0, cnt = 0;
        for(auto &i : events)
            if(i[1] > maxd) maxd = i[1];
        fa.resize(maxd + 2);
        for(int i = 0; i < fa.size(); ++i)
            fa[i] = i;
        for(int i = 0; i < events.size(); ++i){
            int x = events[i][0], y = events[i][1];
            int nxt = find_parent(x);
            if(nxt <= y){
                ++cnt;
                fa[nxt] = nxt + 1;
            }
        }
        return cnt;
    }
};
