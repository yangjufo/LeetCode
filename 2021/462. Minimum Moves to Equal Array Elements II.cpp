class Solution {
public:
    int minMoves2(vector<int>& nums) {        
        sort(nums.begin(), nums.end());
        int moves = 0, mid = nums[nums.size() / 2];
        for (int i = 0; i < nums.size(); i++) {
            moves += abs(nums[i] - mid);
        }
        return moves;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long minVal = INT_MAX, sum = 0, total = 0;
        for (int n : nums) {
            total += n;
        }
        for (int i = 0; i < nums.size(); i++) {
            long ans = ((long) nums[i] * i - sum) + (total - sum - (long) nums[i] * (nums.size() - i));
            minVal = min(minVal, ans);
            sum += nums[i];
        }
        return minVal;
    }
};