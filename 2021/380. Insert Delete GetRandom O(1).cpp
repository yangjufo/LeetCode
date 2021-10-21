class RandomizedSet {
public:    
    unordered_map<int, int> index;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {   
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
         if (index.find(val) != index.end()) {
            return false;
        }
        
        index[val] = nums.size();
        nums.push_back(val);        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index.find(val) == index.end())
            return false;
        
        int back = nums.back();                        
        int delIdx = index[val];                                        
                
        nums[delIdx] = back;
        index[back] = delIdx; // update last element's index in map
        
        nums.pop_back();  
        index.erase(val); // erase val entry from map
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        /* generate secret number between 0 and size - 1: */
        int randIdx = rand() % nums.size();
        
        return nums[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    unordered_map<int, int> indexMap;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            return false;            
        } 
        
        indexMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false;
        }
        int index = indexMap[val];                
        nums[index] = nums.back();
        indexMap[nums[index]] = index;
        nums.pop_back();  
        indexMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 class RandomizedSet {
public:
    int size;
    vector<int> nums;
    unordered_map<int, int> indexes;
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if (indexes.find(val) != indexes.end()) {
            return false;
        }
        if (size >= nums.size()) {
            nums.push_back(val);
        } else {
            nums[size] = val;
        }        
        indexes[val] = size;        
        size++;
        return true;
    }
    
    bool remove(int val) {
        if (indexes.find(val) == indexes.end()) {
            return false;
        }        
        swap(nums[indexes[val]], nums[size - 1]);
        indexes[nums[indexes[val]]] = indexes[val];
        indexes.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        return nums[rand() % size];
    }
    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }        
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */