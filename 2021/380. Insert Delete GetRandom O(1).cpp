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