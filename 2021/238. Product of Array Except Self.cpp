class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res(nums.size());
        
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {            
            res[i] = res[i - 1] * nums[i - 1];            
        }        
        
        int right = 1; 
        for (int i = nums.size() - 1; i > -1; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = {1};
        int left = 1;
        for (int i = 1; i < nums.size(); i++) {
            left *= nums[i - 1];
            res.push_back(left);
        }
        int right = 1;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            right *= nums[i + 1];
            res[i] *= right;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(left);
            left *= nums[i];            
        }
        
        int right = 1;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {            
            res[i] *= right;
            right *= nums[i];            
        }
        
        //[1, 2, 3, 4]
        //    1  2  6
        // 24 12 4  
        
        return res;
    }
};