class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0, total = 0;
        for (int n : nums) {
            sum += n;
            total += counts[sum - k];
            counts[sum] += 1;
        }
        return total;
    }
};