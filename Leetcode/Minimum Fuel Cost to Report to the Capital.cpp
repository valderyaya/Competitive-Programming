class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    #define F first 
    #define S second
    vector<int> v[100001];
    ll d[100001],ans,seat;
    pll dfs(int x, int p){
        d[x]=1;
        ll cnt= seat==1?1:0,rem= seat!=1?1:0;
        for(auto &i:v[x])
            if(i!=p){
                auto c = dfs(i, x);
                ans+= c.F + (c.S?1:0);
                cnt += c.F, rem += c.S;
            }
        cnt += rem / seat;
        rem %= seat;
        return {cnt, rem};
    }
    #define em emplace_back
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(int i=0,x,y;i<roads.size();++i){
            x=roads[i][0], y=roads[i][1];
            v[x].em(y), v[y].em(x);
        }
        seat = seats;
        dfs(0,0);
        return ans;
    }
};
