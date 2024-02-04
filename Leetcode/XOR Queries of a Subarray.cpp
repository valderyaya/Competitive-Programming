class Solution {
public:
    int sum[30001];
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=0;i<arr.size();++i) sum[i+1]=sum[i]^arr[i];
        vector<int> ret;
        for(int i=0;i<queries.size();++i) ret.emplace_back(sum[queries[i].back()+1]^sum[queries[i][0]]);
        return ret;
    }
};
