class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < nums.size()) {
            twoSum(nums, i + 1, nums.size() - 1, nums[i], ans);
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;            
        }
        return ans;
    }
    
    void twoSum(vector<int>& nums, int left, int right, int firstNum, vector<vector<int>>& ans) {        
        while (left < right) {
            if (nums[left] + nums[right] + firstNum == 0) {
                ans.push_back({firstNum, nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;                
            } else if (nums[left] + nums[right] + firstNum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }
};