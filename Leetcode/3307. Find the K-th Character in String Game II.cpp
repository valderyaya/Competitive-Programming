class Solution {
public:
    vector<long long> f = {1};
    char ret = 'a';
    void dfs(long long k, vector<int> &op){
        if(k <= 1) return;
        long long pos = ceil(log2(k));
        dfs(k - f[pos - 1], op);
        if(op[pos - 1])
            ret = (ret == 'z' ? 'a' : ret + 1);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1) return 'a';
        for(int i = 0; ;++i){
            if(f[i] >= k) break;
            f.emplace_back(f[i] << 1);
        }
        dfs(k, operations);
        return ret;
    }
};
