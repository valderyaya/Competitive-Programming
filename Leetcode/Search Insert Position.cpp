class Solution {
public:
    int searchInsert(vector<int>& v, int x) {
        int idx = lower_bound(v.begin(),v.end(),x)-v.begin();
        if(idx<v.size() && v[idx]==x) return idx;
        return idx;
    }
};
