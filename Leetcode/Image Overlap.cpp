class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int> mp;
        int ans=0,n=img1.size();
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(img1[i][j]) v1.push_back({i,j});
                if(img2[i][j]) v2.push_back({i,j});
            }
        for(auto &i:v1) for(auto &j:v2){
            int x=j.first-i.first, y=j.second-i.second;
            ans=max(ans,++mp[{x,y}]);
        }
        return ans;
    }
};
