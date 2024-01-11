class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
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
        vector<int> dp;
        for (int n : nums) {
            int pos = binarySearch(dp, n);
            if (pos >= dp.size()) {
                dp.push_back(n);
            }
            dp[pos] = n;
        }
        return dp.size();
    }

    int binarySearch(vector<int>& dp, int target) {
        if (dp.empty()) {
            return 0;
        }
        int left = 0, right = dp.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return dp[left] < target ? left + 1 : left;
    }
};