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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {           
        vector<int> dp;        
        for (int n : nums) {
            int index = binarySearch(dp, n);
            if (index == dp.size()) {                
                dp.push_back(n);
            } else {
                dp[index] = n;
            }            
        }
        return dp.size();
    }
    
    int binarySearch(vector<int>& dp, int target) {        
        int left = 0, right = dp.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return (dp.empty()) ? 0 : (target > dp[left]) ? left + 1 : left;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int n : nums) {
            auto iter = lower_bound(dp.begin(), dp.end(), n);
            if (iter == dp.end()) {
                dp.push_back(n);
            } else {
                *iter = n;
            }        
        }
        return dp.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int n : nums) {
            auto iter = lower_bound(seq.begin(), seq.end(), n);
            if (iter == seq.end()) {
                seq.push_back(n);
            } else {
                *iter = n;
            }
        }
        return seq.size();
    }        
};