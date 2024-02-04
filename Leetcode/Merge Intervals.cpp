class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int l = v[0][0], r=v[0][1];
        for(int i=1;i<v.size();++i){
            if(r > v[i][1] && l < v[i][0]) continue;
            if(r < v[i][0]){
                ans.push_back(vector<int>{l, r});
                l = v[i][0], r = v[i][1];
            }else r = v[i][1];
        }
        ans.push_back(vector<int>{l, r});
        return ans;
    }
};
