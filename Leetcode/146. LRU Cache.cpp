class LRUCache {
public:
    list<int> cache;
    int cap;
    unordered_map<int, int> key_to_val;
    unordered_map<int, list<int>::iterator> key_to_iter;
    
    void move_to_front(int key){
        cache.erase(key_to_iter[key]);
        cache.push_front(key);
        key_to_iter[key] = cache.begin();
    }

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!key_to_val.count(key)) return -1;
        move_to_front(key);
        return key_to_val[key];
    }
    
    void put(int key, int value) {
        if(key_to_val.count(key)){
            key_to_val[key] = value;
            move_to_front(key);
            return;
        }
        if((int)cache.size() == cap){
            int del = cache.back();
            cache.pop_back();
            key_to_val.erase(del);
            key_to_iter.erase(del);
        }
        key_to_val[key] = value;
        cache.push_front(key);
        key_to_iter[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
