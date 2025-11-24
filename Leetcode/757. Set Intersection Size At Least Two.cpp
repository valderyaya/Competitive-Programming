class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ret = 0, l = -1, r = -1;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];});
        for(auto &v : intervals){
            if(v[0] <= l) continue;
            if(v[0] > r){
                ret += 2;
                r = v[1];
                l = r - 1;
            }else{
                ++ret;
                l = r;
                r = v[1];
            }
        }
        return ret;
    }
};
