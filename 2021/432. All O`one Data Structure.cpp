class AllOne {
public:
    unordered_map<string, int> keyCount;
    map<int, unordered_set<string>> countStrings;
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        keyCount[key]++;
        if (keyCount[key] > 1 && countStrings[keyCount[key] - 1].find(key) != countStrings[keyCount[key] - 1].end()) {
            countStrings[keyCount[key] - 1].erase(key);
            if (countStrings[keyCount[key] - 1].empty()) {
                countStrings.erase(keyCount[key] - 1);
            }
        }
        countStrings[keyCount[key]].insert(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        keyCount[key]--;
        countStrings[keyCount[key] + 1].erase(key);
        if (countStrings[keyCount[key] + 1].empty()) {
            countStrings.erase(keyCount[key] + 1);
        }
        if (keyCount[key] == 0) {
            keyCount.erase(key);
        } else {
            countStrings[keyCount[key]].insert(key);
        }  
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (keyCount.empty()) return "";
        return *(countStrings.rbegin()->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (keyCount.empty()) return "";       
        return *(countStrings.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

class AllOne {
public:
   void inc(string key) {
        
        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
            
        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */