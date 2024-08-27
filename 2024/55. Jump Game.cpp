class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size() && last + 1 < nums.size(); i++) {
            if (i > last) {
                return false;
            }
            last = max(i + nums[i], last);
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0, curr = 0;
        while (maxReach < nums.size() - 1) {
            int nextReach = maxReach;
            for (int i = curr; i <= maxReach; i++) {
                nextReach = max(i + nums[i], nextReach);
            }
            curr = maxReach;
            if (nextReach <= maxReach) {
                return false;
            }
            maxReach = nextReach;
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size() && maxReach < nums.size() - 1; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(i + nums[i], maxReach);
        }
        return true;
    }
};