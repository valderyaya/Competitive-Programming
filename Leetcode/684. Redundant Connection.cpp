class Solution {
public:
    bitset<1001> vis;
    unordered_set<int> s;
    vector<int> v[1001];
    int from[1001] = {}, cycle_node = -1;
    void dfs(int x){
        vis[x] = 1;
        for(auto &i : v[x]){
            if(!vis[i]){
                from[i] = x;
                dfs(i);
            }else if(cycle_node == -1 && from[x] != i){
                cycle_node = i;
                from[i] = x;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto &vec : edges){
            v[vec[0]].emplace_back(vec[1]);
            v[vec[1]].emplace_back(vec[0]);
        }
        dfs(1);
        int cur = cycle_node;
        do{
            s.insert(cur);
            cur = from[cur];
        }while(cur != cycle_node);
        vector<int> ret;
        for(int i = edges.size() - 1; i >= 0; --i){
            if(s.count(edges[i][0]) && s.count(edges[i][1])){
                ret = edges[i];
                break;
            }
        }
        return ret;
    }
};
