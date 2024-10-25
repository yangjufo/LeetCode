class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minVal = min(minVal, nums[i]);
        }
        return sum - minVal * nums.size();
    }
};