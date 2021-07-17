class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;                
                twoSum(nums, j + 1, target - nums[i] - nums[j], nums[i], nums[j]);
            }
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int left, int target, int num1, int num2) {
        int right = nums.size() - 1;
        while (left < right) {                       
            int sum = nums[left] + nums[right];                        
            if (sum == target) {               
                res.push_back({num1, num2, nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                while (left < right && nums[right - 1] == nums[right]) {
                    right--;
                }            
                left++;
                right--;
            } else if (sum > target) {                
                right--;
            } else {
                left++;  
            }            
        }
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                vector<vector<int>> twoRes = twoSum(nums, j + 1, target - nums[i] - nums[j]);
                for (vector<int>& tr : twoRes) {
                    res.push_back({nums[i], nums[j], tr[0], tr[1]});
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        int left = start, right = nums.size() - 1;
        vector<vector<int>> res;
        while (left < right) {
            if (nums[left] + nums[right] == target) {                
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }              
        }
        return res;
    }
};