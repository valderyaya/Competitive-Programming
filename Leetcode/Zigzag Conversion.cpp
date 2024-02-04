class Solution {
public:
    char c[1001][1001];
    string convert(string s, int m) {
        if(m==1) return s;
        bool sta=0;
        for(int i=0,j=0,k=0;k<s.size();++k){
            c[i][j]=s[k];
            if(!sta){
                if(i==m-1) --i,++j,sta=1;
                else ++i;
            }else{
                if(i==0) ++i,sta=0;
                else --i,++j;
            }
        }        
        string ret="";
        for(int i=0;i<m;++i) for(int j=0;j<1000;++j) if(c[i][j]) ret.push_back(c[i][j]);
        return ret;
    }
};
