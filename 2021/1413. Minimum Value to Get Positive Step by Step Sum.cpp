class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSum = INT_MAX, sum = 0;
        for (int n : nums) {
            sum += n;
            minSum = min(sum, minSum);
        }
        return 1 - minSum > 0 ? 1 - minSum : 1;
    }
};