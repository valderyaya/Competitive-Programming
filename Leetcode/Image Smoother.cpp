class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(), m=img[0].size(), dx[]={1,1,1,0,0,0,-1,-1,-1}, dy[]={1,0,-1,1,0,-1,1,0,-1};
        vector<vector<int>> ret;
        for(int i=0;i<n;++i){
            vector<int> row;
            for(int j=0;j<m;++j){
                int cnt=0, sum=0, x, y;
                for(int k=0;k<9;++k){
                    x = i + dx[k], y = j + dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    ++cnt, sum += img[x][y];
                }
                row.push_back(sum/cnt);
            }
            ret.push_back(row);
        }
        return ret;
    }
};
