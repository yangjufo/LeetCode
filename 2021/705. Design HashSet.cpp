class MyHashSet {
public:
    /** Initialize your data structure here. */
    int size = 1234;
    vector<vector<int>> nums;
    MyHashSet() {
        nums.resize(size);
    }
    
    void add(int key) {
        int index = key % size, pos = nums.size();
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i] == key) {
                return;
            }
            if (nums[index][i] == -1 && pos >= nums.size()) {
                pos = nums[index][i];
            }
        }
        if (pos >= nums.size()) {
            nums[index].push_back(key);
        } else {
            nums[index][pos] = key;
        }
    }
    
    void remove(int key) {
        int index = key % size;
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i] == key) {
                nums[index][i] = -1;
            }
        }        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % size, pos = nums.size();
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i] == key) {
                return true;
            }            
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */