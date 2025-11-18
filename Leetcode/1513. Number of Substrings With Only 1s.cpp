class Solution {
public:
    int numSub(string s) {
        const int mod = 1e9+7;
        int cont = 0, sum = 0;
        for(auto &ch : s){
            if(ch == '1'){
                ++cont;
                sum = (sum + cont) % mod;
            }else
                cont = 0;
        }
        return sum;
    }
};
