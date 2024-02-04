class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int p=0,x,y;
        string ret="";
        for(int i=0;i<max(a.size(),b.size());++i){
            x=(i<a.size()?a[i]-'0':0)+(i<b.size()?b[i]-'0':0);
            y=(x+p)%2;
            if(x+p>=2) p=1;
            else p=0;
            if(y) ret.push_back('1');
            else ret.push_back('0');
        }
        if(p) ret.push_back('1');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
