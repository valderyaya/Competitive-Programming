class Solution {
public:
    #define F first
    #define S second
    #define pii pair<int,int>
    vector<pair<int,int>> v;
    
    int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
    int ori(pii a,pii b,pii c){
        pii y={b.F-a.F,b.S-a.S}, z={c.F-a.F,c.S-a.S};
        int x=cross(y,z);
        if(x==0) return 0;
        return x>0?1:-1;
    }
    pii st[3001];
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        for(int i=0;i<trees.size();++i) v.push_back({trees[i][0],trees[i][1]});
        sort(v.begin(),v.end());
        int n=trees.size(), idx=0, idx2;
        for(int i=0;i<n;++i){
            while(idx>1&&ori(st[idx-2],st[idx-1],v[i])<0) idx--;
            st[idx++]=v[i];
        }
        idx2=idx;
        for(int i=n-1;i>=0;i--){
            while(idx2-idx>0&&ori(st[idx2-2],st[idx2-1],v[i])<0) idx2--;
            st[idx2++]=v[i];
        }
        --idx2;
        sort(st,st+idx2);
        n=unique(st,st+idx2)-st;
        vector<vector<int>> ret;
        for(int i=0;i<n;++i){
            vector<int> p = {st[i].F,st[i].S};
            ret.push_back(p);
        }
        return ret;
    }
};
