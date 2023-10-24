class RandomizedSet {
public:
    unordered_map<int, int> indexes;
    vector<int> nums;
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
        int delIndex = indexes[val];
        swap(nums[delIndex], nums.back());
        indexes[nums[delIndex]] = delIndex;
        nums.pop_back();
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