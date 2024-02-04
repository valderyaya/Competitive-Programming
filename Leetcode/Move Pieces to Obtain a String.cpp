class Solution {
public:
    bool canChange(string a, string b){
        int i=0,j=0,n=a.size();
        while(i<=n&&j<=n){
            while(a[i]=='_') ++i;
            while(b[j]=='_') ++j;
            if(i==n||j==n) return i==n&&j==n;
            if(a[i]!=b[j]) return 0;
            if(a[i]=='L'){
                if(i<j) return 0;
            }else if(i>j) return 0;
            ++i, ++j;
        }
        return 0;
    }
};
