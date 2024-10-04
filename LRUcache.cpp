class LRUCache {
    public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        auto it = cache.find(key);
        if(it==cache.end()) // cant find it
            return -1;
        lruList.erase(it->second.second);
        lruList.push_front(key);
        it->second.second = lruList.begin();  // More efficient update cache[key] = pair(it.second.first, lruList.begin());
        return it->second.first;
    }   
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it!=cache.end()){
            //update the value;
            lruList.erase(it->second.second); // safer lruList.erase(cache[key].second.second);
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()}; // Cleaner and preferred cache[key] = pair(value,lruList.begin());
        }
        else {
            // Key doesn't exist, insert a new key-value pair
            if (lruList.size() == capacity) {
            // Cache is full, evict the least recently used key (back of the list)
                int lruKey = lruList.back();
                lruList.pop_back();                // Remove the least recently used element
                cache.erase(lruKey);               // Remove it from the cache
            }
            lruList.push_front(key);               // Add new key to the front of the list
            cache[key] = {value, lruList.begin()}; // Insert new key-value pair in the cache
        }

    }
    private: 
        unordered_map<int,pair<int,list<int>::iterator>> cache;
        list<int> lruList;
        int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */