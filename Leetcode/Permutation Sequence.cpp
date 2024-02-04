class Solution {
public:
    string getPermutation(int n, int k) {
        string s="123456789", res="";
        int p[10]={1,1};
        for(int i=2;i<10;++i) p[i]=p[i-1]*i;
        k=(k-1)%p[n];
        int pp;
        for(int i=n-1;~i;--i){
            pp=k/p[i];
            res+=s[pp];
            for(int j=pp;j<i;++j) s[j]=s[j+1];
            k%=p[i];
        }
        return res;
    }
};
