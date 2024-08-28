class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> indexes;
    RandomizedSet() {
    }

    bool insert(int val) {
        if (indexes.find(val) != indexes.end()) {
            return false;
        }
        indexes[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (indexes.find(val) == indexes.end()) {
            return false;
        }
        int val_index = indexes[val];
        swap(nums[val_index], nums.back());
        nums.pop_back();
        indexes[nums[val_index]] = val_index;
        indexes.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */