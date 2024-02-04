class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int kv) {
        int s[101][101]={}, n = mat.size(), m = mat[0].size(), ans=-INT_MAX;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                s[i][j] = mat[i-1][j-1]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
        //for(int i=0;i<=n;++i)
        //    for(int j=0;j<=m;++j) cout<<s[i][j]<<" \n"[j==m];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                for(int k=i;k<=n;++k)
                    for(int l=j;l<=m;++l){
                        int x = s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1];
                        //cout<<x<<endl;
                        if(x <= kv) ans = max(ans, x);
                    }
        return ans;
    }
};
