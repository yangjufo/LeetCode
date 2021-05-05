class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums.push_back(sum);
        }
        return sums;
    }
};