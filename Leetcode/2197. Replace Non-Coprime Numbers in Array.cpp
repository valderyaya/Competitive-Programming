class Solution {
public:
    int LCM(int x, int y){
        return x / __gcd(x, y) * y;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret;
        for(auto &i : nums){
            int x = i, g;
            while(!ret.empty()){
                g = __gcd(ret.back(), x);
                if(g == 1) break;
                x = LCM(ret.back(), x);
                ret.pop_back();
            }
            ret.emplace_back(x);
        }
        return ret;
    }
};
