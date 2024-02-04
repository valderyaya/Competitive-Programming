class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),ans=-1;
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==1) a.push_back({i,j});
                else b.push_back({i,j});
        for(auto &[x,y]:b){
            int mn=1e9;
            for(auto &[xx,yy]:a) mn=min(mn,abs(xx-x)+abs(yy-y));
            if(mn!=1e9) ans=max(ans,mn);
        }
        return ans;
    }
};
