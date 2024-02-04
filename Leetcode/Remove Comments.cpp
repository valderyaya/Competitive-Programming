class Solution {
public:
    vector<string> removeComments(vector<string>& v) {
        vector<string> ret;
        bool chk=0;
        string s="";
        for(int i=0;i<v.size();++i){
            if(!chk) s="";
            for(int j=0;j<v[i].size();++j){
                if(j+1<v[i].size()&&v[i][j]=='/'&&v[i][j+1]=='/'){
                    if(!chk) break;
                    else continue;
                }else if(j+1<v[i].size()&&v[i][j]=='/'&&v[i][j+1]=='*'){
                    if(!chk){
                        chk=1;
                        ++j;
                    }else continue;
                }else if(j+1<v[i].size()&&v[i][j]=='*'&&v[i][j+1]=='/'){
                    if(chk){
                        chk=0;
                        ++j;
                    }else{
                        s.push_back(v[i][j]);
                        continue;
                    }
                }else if(!chk) s.push_back(v[i][j]);
            }
            if(s!=""&&!chk) ret.push_back(s);
        }
        return ret;
    }
};
