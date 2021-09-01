class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, count = 0, prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while (prod >= k && start <= i) {
                prod /= nums[start];
                start++;
            }
            if (prod < k && start <= i) {
                count += i - start + 1;
            }                            
        }
        return count;
    }
};