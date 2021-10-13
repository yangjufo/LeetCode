class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int>& nums) {
        this->nums = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuNums(nums);
        for (int i = 0; i < nums.size(); i++) {
            swap(shuNums[i], shuNums[i + rand() % (nums.size() - i)]);
        }
        return shuNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<bool> visited(nums.size(), false);
        vector<int> shuffledNums;
        while (shuffledNums.size() < nums.size()) {
            int index = rand() % nums.size();
            if (visited[index]) continue;
            shuffledNums.push_back(nums[index]);
            visited[index] = true;
        }
        return shuffledNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuNums(nums);
        for (int i = 0; i < nums.size(); i++) {
            swap(shuNums[i], shuNums[i + rand() % (nums.size() - i)]);
        }
        return shuNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

 class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> res = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            swap(res[i], res[i + rand() % (n - i)]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */