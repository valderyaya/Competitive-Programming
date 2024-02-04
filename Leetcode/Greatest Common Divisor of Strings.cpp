class Solution {
public:
    bool chk(string &a,string &b,string &c){
        int i=0,j=0,k=0;
        for(;i<a.size();++i,++j,k=(k+1)%c.size())
            if(a[i]!=c[k]) return 0;
            else if(j<b.size()&&b[j]!=c[k]) return 0;
        return !k;
    }
    string gcdOfStrings(string str1, string str2) {
        int x=str1.size(), y=str2.size();
        if(x < y) swap(str1,str2);
        for(int i=y;i;--i){
            if(y%i || x%i) continue;
            string s=str2.substr(0,i);
            if(chk(str1,str2,s)) return s;
        }
        return "";
    }
};
