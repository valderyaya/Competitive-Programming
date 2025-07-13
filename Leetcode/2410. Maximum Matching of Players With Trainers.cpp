class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, cnt = 0;
        for(int n = players.size(), m = trainers.size(); i < n && j < m; ++j){
            if(players[i] <= trainers[j]){
                ++cnt;
                ++i;
            }
        }
        return cnt;
    }
};
