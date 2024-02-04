class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn=1e9,mn2=1e9;
        for(auto &i:prices){
            if(i < mn){
                mn2 = mn;
                mn = i;
            }else if(i >= mn){
                mn2 = min(i, mn2);
            }
        }
        if(mn + mn2 <= money) return money - mn - mn2;
        return money;
    }
};
