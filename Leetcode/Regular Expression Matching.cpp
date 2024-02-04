class Solution {
public:
    bool isMatch(string s, string p) {
        bool f[35][35]={1};
        for(int i=2;i<=p.size()&&p[i-1]=='*';i+=2) f[0][i]=1;
        for(int i=1;i<=s.size();++i)
            for(int j=1;j<=p.size();++j)
                if(s[i-1]==p[j-1]||p[j-1]=='.') f[i][j]=f[i-1][j-1];
                else if(p[j-1]=='*') f[i][j]=f[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&f[i-1][j];
        return f[s.size()][p.size()];
    }
};

// aa a*
