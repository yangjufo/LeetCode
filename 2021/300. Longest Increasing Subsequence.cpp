class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        int dp[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++) dp[i] = 0;
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < dp[0]) dp[0] = nums[i];
            else if (nums[i] > dp[len - 1]) {                
                dp[len] = nums[i];
                len++;
            } else {
                int pos = binarySearch(dp, 0, len, nums[i]);            
                dp[pos] = nums[i];
            }
        }
        return len;
    }
    
    int binarySearch(int* dp, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] >= target) right = mid;
            else left = mid + 1;
        }            
        return right;
    }
};