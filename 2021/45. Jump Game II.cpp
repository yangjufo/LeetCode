class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int maxPos = nums[0];
        int maxSteps = nums[0];
        
        int jumps = 1;
        for (int i = 1; i < n; i++) {
            if (maxSteps < i) {
                jumps++;
                maxSteps = maxPos;
            }
            maxPos = max(maxPos, nums[i] + i);
        }
        
        return jumps;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int maxPos = nums[0];
        int maxSteps = nums[0];
        
        int jumps = 1;
        for (int i = 1; i < n; i++) {
            if (maxSteps < i) {
                jumps++;
                maxSteps = maxPos;
            }
            maxPos = max(maxPos, nums[i] + i);
        }
        
        return jumps;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, maxPos = nums[0], currPos = 0;
        for (int i = 0; i < nums.size() && currPos + 1 < (int)nums.size(); i++) {     
            if (i > currPos) {
                currPos = maxPos;
                steps++;
            }
            if (i + nums[i] > maxPos) {
                maxPos = i + nums[i];
            }
        } 
        return steps;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, maxPos = 0, currPos = 0;
        for (int i = 0; i < nums.size() && currPos + 1 < nums.size(); i++) {
            if (i > currPos) {
                currPos = maxPos;
                step++;
            }
            maxPos = max(maxPos, nums[i] + i);
        }
        return step;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int currMax = -1, nextMax = 0, count = -1;
        for (int i = 0; i < nums.size() && currMax + 1 < nums.size(); i++) {
            if (i > currMax) {
                count++;
                currMax = nextMax;
            }
            nextMax = max(nextMax, i + nums[i]);
        }
        return count;
    }
};