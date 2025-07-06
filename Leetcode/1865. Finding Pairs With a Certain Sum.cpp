class FindSumPairs {
public:
    vector<int> v1, v2;
    unordered_map<int, int> cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &x : nums2)
            cnt[x]++;
        v1 = nums1, v2 = nums2;
    }
    
    void add(int index, int val) {
        --cnt[v2[index]];
        v2[index] += val;
        ++cnt[v2[index]];
    }
    
    int count(int tot) {
        int ret = 0, diff;
        for(auto &x : v1){
            diff = tot - x;
            if(cnt.count(diff))
                ret += cnt[diff];
        }
        return ret;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
