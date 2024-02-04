class Solution {
public:
    int bit[1000001];
    #define lb(x) x&-x
    void add(int x,int y){
        for(;x<=1000000;x+=lb(x)) bit[x]=max(bit[x],y);
    }
    int qry(int x){
        int ret=0;
        for(;x;x-=lb(x)) ret=max(ret,bit[x]);
        return ret;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v(ages.size());
        int n=ages.size(),ans=0;
        for(int i=0;i<n;++i) v[i]={ages[i],scores[i]};
        sort(v.begin(),v.end());
        for(int i=0;i<n;++i) add(v[i].second, qry(v[i].second)+v[i].second);
        return qry(1000000);
    }
};
