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