class Solution {
public:
    vector<int> v[100005];
    bitset<100001> vis;
    void dfs(int x){
        vis[x]=1;
        for(auto &i:v[x])
            if(!vis[i]) dfs(i);
    }
    int makeConnected(int n, vector<vector<int>>& ve) {
        int cnt=0, m = ve.size();
        
        for(int i=0;i<ve.size();++i){
            v[ve[i][0]].push_back(ve[i][1]);
            v[ve[i][1]].push_back(ve[i][0]);
        }
        for(int i=0;i<n;++i)
            if(!vis[i]) ++cnt,dfs(i);
        if(m+1<n) return -1;
        else return cnt-1;
    }
};
