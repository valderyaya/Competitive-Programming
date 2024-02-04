class Solution {
public:
    int cnt[100005],lmt,tot;
    void add(int x){
        ++tot;
        if(++cnt[x]==1) ++lmt;
    }
    void del(int x){
        --tot;
        if(--cnt[x]==0) --lmt;
    }
    int totalFruit(vector<int>& v){
        int mx=0;
        for(int i=0,j=0;i<v.size();++i){
            add(v[i]);
            while(lmt>2) del(v[j++]);
            mx=max(mx,tot);
        }
        return mx;
    }
};
