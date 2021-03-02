class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % k != 0) return false;
        
        return dfs(nums, sum / k, 0, 0, k);
    }
    
    bool dfs(vector<int>& nums, int sum, int curr, int start, int k) {        
        if (k == 1) return true;
        if (curr > sum) return false;
        if (curr == sum) return dfs(nums, sum, 0, 0, k - 1);
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > 0) {
                int tmp = nums[i];
                nums[i] = 0;
                if (dfs(nums, sum, curr + tmp, i + 1, k)) {
                    return true;
                }
                nums[i] = tmp;
            }
        }
        return false;
    } 
};