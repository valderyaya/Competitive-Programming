class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c=0;
        while(left < right) ++c, left>>=1, right>>=1;
        return left << c;
    }
};
