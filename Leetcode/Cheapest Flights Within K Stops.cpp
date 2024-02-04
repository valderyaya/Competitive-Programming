class Solution {
public:
    int dis[2][105],now=1,prv;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(int i=0;i<n;++i) dis[0][i]=dis[1][i]=1e9;
        dis[prv][src]=dis[now][src]=0;
        for(int i=0;i<k+1;++i){
            for(int j=0;j<flights.size();++j){
                int u=flights[j][0], v=flights[j][1], w=flights[j][2];
                dis[now][v]=min(dis[now][v],dis[prv][u]+w);
            }
            swap(now,prv);
        }
        return dis[prv][dst]==1e9?-1:dis[prv][dst];
    }
};
