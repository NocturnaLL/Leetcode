class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (cache_map_.find(key) == cache_map_.end()) {
            return -1;
        } else {
            // Move the accessed key to the front of the list (most recent)
            cache_items_list_.splice(cache_items_list_.begin(), cache_items_list_, cache_map_[key]);
            return cache_map_[key]->second;
        }
    }

    void put(int key, int value) {
        if (cache_map_.find(key) != cache_map_.end()) {
            // Key exists, update value and move it to the front
            cache_map_[key]->second = value;
            cache_items_list_.splice(cache_items_list_.begin(), cache_items_list_, cache_map_[key]);
        } else {
            // Key does not exist, insert a new item
            if (cache_items_list_.size() == capacity_) {
                // Cache is full, remove the least recently used item (back of the list)
                int key_to_remove = cache_items_list_.back().first;
                cache_items_list_.pop_back();
                cache_map_.erase(key_to_remove);
            }
            // Insert the new key-value pair at the front of the list
            cache_items_list_.emplace_front(key, value);
            cache_map_[key] = cache_items_list_.begin();
        }
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> cache_items_list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map_;
};