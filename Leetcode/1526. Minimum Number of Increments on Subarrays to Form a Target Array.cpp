class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ret = 0;
        for(int i = 0; i < target.size(); ++i){
            if(i == 0) ret += target[i];
            else if(target[i] > target[i - 1]) ret += target[i] - target[i - 1];
        }
        return ret;
    }
};
