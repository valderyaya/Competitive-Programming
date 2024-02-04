class Solution {
public:
    int f[40]={0,1,1};
    int tribonacci(int n) {
        if(n<3 || f[n]) return f[n];
        return f[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};
