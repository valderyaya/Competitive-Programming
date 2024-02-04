class Solution {
public:
    struct qwq{
        int x,step,pre;
    };
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> v[101];
        vector<int> dis(n,-1);
        for(int i=0;i<redEdges.size();++i) v[redEdges[i][0]].push_back({redEdges[i][1],0});
        for(int i=0;i<blueEdges.size();++i) v[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        queue<qwq> q;
        bitset<2> vis[101];
        q.emplace(qwq{0,0,-1});
        dis[0]=0; vis[0][0]=vis[0][1]=1;
        while(!q.empty()){
            auto [x,step,pre]=q.front(); q.pop();
            for(auto &i:v[x]){
                if(!vis[i.first][i.second]&&pre!=i.second){
                    vis[i.first][i.second]=1;
                    q.emplace(qwq{i.first, step+1, i.second});
                    if(dis[i.first]==-1) dis[i.first]=step+1;
                }
            }
        }
        return dis;
    }
};
