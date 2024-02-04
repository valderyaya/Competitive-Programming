class Solution {
public:
    int a[10][10];
    bool f=0;
    vector<pair<int,int>> v;
    bool ck(){
        for(int i=0;i<9;++i) {
            bool c[10]={};
            for(int j=0;j<9;++j){
                if(!a[i][j]) continue;
                if(c[a[i][j]]) return 0;
                else c[a[i][j]]=1;
            }
        }
        for(int i=0;i<9;++i){
            bool c[10]={};
            for(int j=0;j<9;++j){
                if(!a[j][i]) continue;
                if(c[a[j][i]]) return 0;
                else c[a[j][i]]=1;
            }
        }
        for(int i=0;i<9;i+=3)
            for(int j=0;j<9;j+=3){
                bool c[10]={};
                for(int k=0;k<3;++k)
                    for(int l=0;l<3;++l){
                        if(!a[i+k][j+l]) continue;
                        if(c[a[i+k][j+l]]) return 0;
                        else c[a[i+k][j+l]]=1;
                    }
            }
        return 1;
    }
    void dfs(int id, vector<vector<char>>& brd){
        if(id==v.size()){
            for(int i=0;i<9;++i)
                for(int j=0;j<9;++j) brd[i][j]=char(a[i][j]+'0');
           return f=1,void();
        }
        for(int i=1;i<10;++i){
            a[v[id].first][v[id].second]=i;
            if(ck()) dfs(id+1, brd);
            if(f) return;
            a[v[id].first][v[id].second]=0;
        }
    }
    void solveSudoku(vector<vector<char>>& brd) {
        for(int i=0;i<9;++i) for(int j=0;j<9;++j){
            if(brd[i][j]=='.') v.push_back({i,j});
            else a[i][j]=brd[i][j]-'0';
        }
        dfs(0, brd);
    }
};
