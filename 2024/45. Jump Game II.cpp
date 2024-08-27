class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int curr = 0, last = 0, step = 1;
        for (int i = 0; i < nums.size() && last + 1 < nums.size(); i++) {
            if (i > curr) {
                step += 1;
                curr = last;
            }
            last = max(i + nums[i], last);
        }
        return step;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, step = 0, currReach = 0;
        while (true) {
            if (maxReach >= nums.size() - 1) {
                return step;
            }
            step += 1;
            int nextReach = maxReach;
            for (int i = currReach; i <= maxReach; i++) {
                nextReach = max(nextReach, i + nums[i]);
            }
            currReach = maxReach;
            maxReach = nextReach;
        }
        return step;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int maxReach = 0, step = 1, curr = 0;
        for (int i = 0; i < nums.size() && maxReach < nums.size() - 1; i++) {
            if (i > curr) {
                step += 1;
                curr = maxReach;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return step;
    }
};