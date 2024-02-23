class Solution {
public:
    #define pii pair<int,int>
    #define F first
    #define S second
    int mostBooked(int n, vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int cnt[101]={}, mx = 0;
        long long tms[101]={};
        for(auto &i:v){
            int l = i[0] , r = i[1], id = 0, f=1;
            long long val = 1e18;
            for(int j=0;j<n;++j){
                if(tms[j] < val) val = tms[j], id=j;
                if(tms[j] <= l){
                    ++cnt[j];
                    tms[j] = r;
                    f=0;
                    break;
                }
            }
            if(f){
                ++cnt[id];
                tms[id] += r-l;
            }
        }
        for(int i = 1; i < n; ++i)
            if(cnt[i] > cnt[mx]) mx = i;
        for(int i = 0; i < n; ++i) cout<<cnt[i]<<' ';    
        return mx;
    }
};
