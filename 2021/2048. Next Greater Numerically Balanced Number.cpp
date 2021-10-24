class Solution {
public:
    int nextBeautifulNumber(int n) {
        int digit = 0, tmp = n;
        while (tmp > 0) {
            digit++;
            tmp /= 10;
        }
        if (digit == 0) {
            return 1;
        }
        if (digit == 7) {
            return 1224444;
        }
        vector<int> nums;
        switch(digit) {
            case 1:
                backtrack(nums, {0, 1}, 0, 1);
                nums.push_back(22);
                break;
            case 2:
                backtrack(nums, {0, 0, 2}, 0, 2);
                nums.push_back(122);
                break;
            case 3:
                backtrack(nums, {0, 1, 2}, 0, 3);
                backtrack(nums, {0, 0, 0, 3}, 0, 3);
                nums.push_back(1333);
                break;
            case 4:
                backtrack(nums, {0, 1, 0, 3}, 0, 4);
                backtrack(nums, {0, 0, 0, 0, 4}, 0, 4);
                nums.push_back(14444);
                break;
            case 5:
                backtrack(nums, {0, 1, 0, 0, 4}, 0, 5);
                backtrack(nums, {0, 0, 2, 3}, 0, 5);
                backtrack(nums, {0, 0, 0, 0, 0, 5}, 0, 5);
                nums.push_back(122333);
                break;
            case 6:
                backtrack(nums, {0, 1, 2, 3}, 0, 6);
                backtrack(nums, {0, 1, 0, 0, 0, 5}, 0, 6);
                backtrack(nums, {0, 0, 2, 0, 4}, 0, 6);
                backtrack(nums, {0, 0, 0, 0, 0, 0, 6}, 0, 6);
                nums.push_back(1224444);
                break;
            default:
                break;
        }
        sort(nums.begin(), nums.end());        
        for (int num : nums) {
            if (n < num) {
                return num;
            }
        }
        return 1224444;
    }
    
    void backtrack(vector<int>& nums, vector<int> count, int curr, int digit) {
        if (digit == 0) {
            nums.push_back(curr);
            return;
        }
        for (int i = 1; i < count.size(); i++) {
            if (count[i] > 0) {
                count[i] -= 1;
                backtrack(nums, count, curr * 10 + i, digit - 1);
                count[i] += 1;
            }
        }        
    }
};