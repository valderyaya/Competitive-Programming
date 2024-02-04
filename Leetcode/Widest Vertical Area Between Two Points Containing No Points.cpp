class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        int ret=0;
        sort(p.begin(), p.end());
        for(int i=1;i<p.size();++i) ret=max(ret, p[i][0]-p[i-1][0]);
        return ret;
    }
};
