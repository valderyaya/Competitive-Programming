class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;
        for(int i = 1; i <= n; ++i){
            int s = 0, x = i;
            while(x){
                s += x % 10;
                x /= 10;
            }
            mp[s].push_back(i);
        }
        int mx = 0, cnt = 0;
        for(auto &i : mp){
            if(i.second.size() > mx){
                mx = i.second.size();
                cnt = 1;
            }else if(mx == i.second.size())
                ++cnt;
        }
        return cnt;
    }
};
