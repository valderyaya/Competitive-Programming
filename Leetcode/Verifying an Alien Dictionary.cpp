class Solution {
public:
    int rk[130];
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> v=words;
        for(int i=0;i<order.size();++i) rk[order[i]]=i;
        auto cmp=[&](string x,string y){
            for(int i=0;i<min(x.size(),y.size());++i) if(x[i]!=y[i]) return rk[x[i]]<rk[y[i]];
            return x.size()<y.size();
        };
        sort(v.begin(),v.end(),cmp);
        return v==words;
    }
};
