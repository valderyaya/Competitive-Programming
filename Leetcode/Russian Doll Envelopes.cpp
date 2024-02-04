class Solution {
public:
    #define F first
    #define S second
    #define pii pair<int,int>
    static bool cmp(pii x, pii y){return x.F==y.F?x.S>y.S:x.F<y.F;}
    int maxEnvelopes(vector<vector<int>>& ve) {
        vector<pii> v;
        for(auto &i:ve) v.emplace_back(i[0],i[1]);
        sort(v.begin(), v.end(), cmp);
        vector<int> d;
        for(auto &i: v){
            if(d.empty() || d.back() < i.S) 
                d.emplace_back(i.S);
            else
                d[lower_bound(d.begin(), d.end(), i.S) - d.begin()] = i.S;
        }
        return d.size();
    }
};

