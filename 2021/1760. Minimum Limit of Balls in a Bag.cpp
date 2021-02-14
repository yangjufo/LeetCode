class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {        
        sort(nums.begin(), nums.end(), greater<int>());
        int left = 1, right = nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canDivide(vector<int>& nums, int maxOperations, int target) {
        for (int i = 0; i < nums.size() && maxOperations >= 0 && nums[i] > target; i++) {                 
            maxOperations -= (nums[i] + target - 1) / target - 1;
        }
        return maxOperations >= 0;
    }
    
};


class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {        
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int a : nums)
                count += (a - 1) / mid;
            if (count > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};