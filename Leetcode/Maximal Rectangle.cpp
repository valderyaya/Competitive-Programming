class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int l[202][202]={},r[202][202]={},up[202][202]={},ans=0;
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[i].size();++j) {
                if(mat[i][j]=='1') {
                    l[i][j]=j?l[i][j-1]+1:1;
                    up[i][j]=i?up[i-1][j]+1:1;
                }
            }
            for(int j=mat[i].size()-1;j>=0;--j) if(mat[i][j]=='1') r[i][j]=j==mat[i].size()-1?1:r[i][j+1]+1;
        }
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[i].size();++j) {
                if(mat[i][j]=='1'){
                    if(i&&mat[i-1][j]=='1'){
                        l[i][j]=min(l[i][j],l[i-1][j]);
                        r[i][j]=min(r[i][j],r[i-1][j]);
                    }
                    ans=max(ans,up[i][j]*(r[i][j]+l[i][j]-1));
                }
            }
        }
        return ans;
    }
};
