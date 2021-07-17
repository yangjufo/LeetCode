class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> indexMap;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {                
        indexMap[val].insert(nums.size());
        nums.push_back(val);
        return indexMap[val].size() <= 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false;
        };
        int index = *(indexMap[val].begin());    
        indexMap[nums.back()].erase(nums.size() - 1);
        indexMap[nums.back()].insert(index);
        nums[index] = nums.back();
        nums.pop_back();
        if (nums.size() == index || nums[index] != val) {
            indexMap[val].erase(index);        
            if (indexMap[val].empty()) {            
                indexMap.erase(val);
            }
        }        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedCollection {
public:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> indexMap;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int ret = indexMap.find(val) == indexMap.end();
        indexMap[val].push_back(nums.size());
        nums.push_back({val, indexMap[val].size() - 1});
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        int ret = indexMap.find(val) != indexMap.end();
        if (ret) {
            auto last = nums.back();
            indexMap[last.first][last.second] = indexMap[val].back();
            nums[indexMap[last.first][last.second]] = {last.first, last.second};
            nums.pop_back();
            indexMap[val].pop_back();
            if (indexMap[val].empty()) {
                indexMap.erase(val);
            }
        }
        return ret;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */