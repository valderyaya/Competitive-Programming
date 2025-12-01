class Solution {
public:
    bool check(vector<int>& batteries, long long target, int n){
        long long sum = 0;
        for(auto &battery: batteries){
            sum += min((long long)battery, target);
        }
        return sum >= target * n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans, mid, R, L = 0, sum = 0;
        for(auto &battery : batteries){
            sum += battery;
        }
        R = sum / n + 1;
        while(L < R){
            mid = (R - L) / 2 + L;
            if(check(batteries, mid, n)){
                ans = mid;
                L = mid + 1;
            }else{
                R = mid;
            }
        }
        return ans;
    }
};
