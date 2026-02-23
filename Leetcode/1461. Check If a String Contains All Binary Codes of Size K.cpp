class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = 1 << k, mask = n - 1, cur = 0;
        bitset<1048576> vis;
        for(int i = 1; i <= s.size(); ++i){
            cur = ((cur << 1) & mask) | (s[i - 1] == '1');
            if(i >= k && !vis[cur]){
                if(--n == 0) return true;
                vis[cur] = 1;
            } 
        }
        return false;
    }
};
