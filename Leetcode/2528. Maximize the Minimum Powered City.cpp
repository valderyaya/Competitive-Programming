class Solution {
public:
    bool check(vector<long long>& diff, long long mid, int k, int r, int n){
        vector<long long> d = diff;
        long long sum = 0, df;
        for(int i = 0; i < n; ++i){
            sum += d[i];
            if(sum < mid){
                df = mid - sum;
                if(k < df) return false;
                k -= df;
                sum += df;
                d[min(n, i + 2 * r + 1)] -= df;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long R = 0, L = 1e18, mid, ans;
        vector<long long> diff(n + 1);
        for(int i = 0, mn, mx; i < n; ++i){
            mn = max(0, i - r);
            mx = min(n, i + r + 1);
            diff[mn] += stations[i];
            diff[mx] -= stations[i];
            R += stations[i];
            L = min(L, (long long)stations[i]);
        }
        R += k + 1;
        while(R > L){
            mid = (R - L) / 2 + L;
            // cout << L << ' ' << R << ' ' << mid << endl;
            if(check(diff, mid, k, r, n)){
                L = mid + 1;
                ans = mid;
                // cout << "yes: " << ans << endl;
            }
            else 
                R = mid; 
        }
        return ans;
    }
};
