class Solution {
public:
    struct segment_tree{
        long long cnt;
        segment_tree *lson, *rson;
        segment_tree():cnt(0), lson(nullptr), rson(nullptr){}
        void up(){
            cnt = 0;
            if(lson) cnt = lson -> cnt;
            if(rson) cnt += rson -> cnt;
        }
        void modify(long long l, long long r, long long index){
            if(l == r) return this->cnt++, void();
            long long mid = (r - l) / 2 + l;
            if(index <= mid){
                if(!lson) lson = new segment_tree();
                lson -> modify(l, mid, index);
            }
            else{
                if(!rson) rson = new segment_tree();
                rson -> modify(mid + 1, r, index);
            }
            up();
        }
        long long query(long long l, long long r, long long ql, long long qr){
            if(ql > qr) return 0;
            if(ql <= l && r <= qr) return this->cnt;
            long long mid = (r - l) / 2 + l, ret = 0;
            if(ql <= mid && lson) ret = lson -> query(l, mid, ql, qr);
            if(qr > mid && rson) ret += rson -> query(mid + 1, r, ql, qr);
            return ret;
        }
    };
    const long long L = INT_MIN, R = INT_MAX;
    int reversePairs(vector<int>& nums) {
        segment_tree *rt = new segment_tree();
        long long ans = 0, bound;
        for(auto &num : nums){
            bound = (long long)num * 2;
            ans += rt -> query(L, R, bound + 1, R);
            rt -> modify(L, R, num);
        }
        return (int)ans;
    }
};
