class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];            
        
        return max(robOne(nums, 0, nums.size() - 2), robOne(nums, 1, nums.size() - 1));
    }
    
    int robOne(vector<int>& nums, int left, int right) {        
        int prev = 0, curr = 0;
        for (int i = left; i <= right; i++) {
            int tmp = max(nums[i] + prev, curr);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prev11 = 0, prev12 = 0, prev21 = 0, prev22 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size()) {
                int curr1 = max(prev11, prev12 + nums[i]);
                prev12 = prev11;
                prev11 = curr1;
            }
            if (i != 0) {
                int curr2 = max(prev21, prev22 + nums[i]);
                prev22 = prev21;
                prev21 = curr2;
            }
        }
        return max(prev11, prev21);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0, res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        res = max(res, prev1);
        prev2 = prev1 = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(res, prev1);
    }
};