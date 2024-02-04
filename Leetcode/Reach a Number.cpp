class Solution {
public:
    int reachNumber(int target) {
        long long x=ceil((-1.0+sqrt(1+8.0*abs((long long)target)))/2);
        long long y=x*(1+x)/2;
        if((y-target)%2==0)  return x;
        return x+(x&1?2:1);
    }
};
