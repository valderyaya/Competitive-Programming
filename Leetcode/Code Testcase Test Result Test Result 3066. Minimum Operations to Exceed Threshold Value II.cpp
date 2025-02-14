class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        int cnt = 0;
        while(pq.size() > 1 && pq.top() < k){
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();
            ++cnt;
            pq.emplace(min(x,y) * 2 + max(x, y));
        }
        return cnt;
    }
};
