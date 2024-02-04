class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
    
    }
    
    bool insert(int val) {
        if(mp.count(val)) return 0;
        mp[val] = v.size();
        v.emplace_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return 0;
        int tmp = v.back();
        mp[tmp] = mp[val];
        v[mp[val]] = tmp;
        v.pop_back();
        mp.erase(val);
        return 1;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
