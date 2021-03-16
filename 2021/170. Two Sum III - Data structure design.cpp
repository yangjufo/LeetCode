class TwoSum {
public:
    unordered_map<int, int> nums;
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {      
        nums[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto& iter : nums) {
            if ((iter.first > 0 && value < 0 && value < iter.first + INT_MIN) || (iter.first < 0 && value > 0 && value > iter.first + INT_MAX)) continue;
            if (nums.find(value - iter.first) != nums.end() && (value - iter.first != iter.first || nums[iter.first] > 1)) {                
                return true;
            }        
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */