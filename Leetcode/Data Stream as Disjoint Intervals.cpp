class SummaryRanges {
public:
    struct qwq{
        mutable int l,r;
        bool operator<(const qwq &x)const{
            return  l!=x.l?l<x.l:r<x.r;
        }
    };
    set<qwq> s;
    SummaryRanges() {
        s.clear();
    }

    void addNum(int value) {
        if(s.empty()) return s.insert(qwq{value,value}),void();
        auto it = s.lower_bound(qwq{value,0});
        bool c=0;
        if(it->l<=value && value<=it->r) return;
        else if(it!=s.begin()){
            auto p = prev(it);
            if(p->l<=value && p->r >=value) return;
        }
        if(it!=s.begin()){
            auto prv = prev(it);
            if(prv->r+1==value){
                c=1;
                prv->r=value;
            }
        }
        if(c){
            if(it!=s.begin()){
                auto prv=prev(it);
                if(prv->r+1==it->l){
                    prv->r = it->r;
                    s.erase(it);
                }
            }
        }else{
            if(it->l-1==value){
                it->l = value;
                c=1;
            }
        }
        if(!c) s.insert(qwq{value,value});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto &i:s){
            vector<int> v;
            v.emplace_back(i.l);
            v.emplace_back(i.r);
            ret.emplace_back(v);

        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
