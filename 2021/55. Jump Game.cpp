class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
        int curr = 0;
        for (int i = 0; i < nums.size() && i <= curr && curr < nums.size() - 1; i++) {
            curr = max(i + nums[i], curr);
        }
        return curr >= nums.size() - 1;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size() && maxPos >= i; i++) {
            maxPos = max(nums[i] + i, maxPos);
        }
        return maxPos + 1 >=  nums.size();
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currMax = 0;
        for (int i = 0; i < nums.size() && i <= currMax && currMax < nums.size(); i++) {
            currMax = max(currMax, nums[i] + i);
        }
        return currMax + 1 >= nums.size();
    }
};