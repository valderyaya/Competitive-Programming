class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> df(n, vector<int>(n, 0));
        for(auto &vec : queries){
            int x1 = vec[0], y1 = vec[1], x2 = vec[2], y2 = vec[3];
            df[x1][y1]++;
            if(x2 + 1 < n) df[x2 + 1][y1]--;
            if(y2 + 1 < n) df[x1][y2 + 1]--;
            if(x2 + 1 < n && y2 + 1 < n) df[x2 + 1][y2 + 1]++;
        }
        // for(int i = 0; i < n; ++i)
        //     for(int j = 0; j < n; ++j)
        //         cout << df[i][j] << " \n"[j==n-1];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                df[i][j] += (i > 0 ? df[i-1][j] : 0) + (j > 0 ? df[i][j-1] : 0) - ((i > 0 && j > 0) ? df[i-1][j-1] : 0);
        return df;
    }
};

// 0,0  1,2


