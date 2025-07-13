class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, cnt = 0;
        for(int n = g.size(), m = s.size(); i < n && j < m; ++j){
            if(g[i] <= s[j]){
                ++cnt;
                ++i;
            }
        }
        return cnt;
    }
};
