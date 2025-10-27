class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0, ret = 0, last = 0;
        for(int i = 0; i < bank.size(); ++i){
            cnt = 0;
            for(auto &j : bank[i]) if(j == '1') ++cnt;
            // cout << cnt << endl;
            ret += last * cnt;
            if(cnt) last = cnt;
        }
        return ret;
    }
};
