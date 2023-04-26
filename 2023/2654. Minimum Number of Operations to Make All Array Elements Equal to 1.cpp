class Solution {
public:
    int minOperations(vector<int>& nums) {
        int oneCount = 0;
        for (int n : nums) {
            if (n == 1) {
                oneCount++;
            }
        }
        for (int m = 1; m <= nums.size(); m++) {
           for (int i = 0; i + m <= nums.size(); i++) {
               int curr = nums[i];
               for (int j = 1; j < m; j++) {
                   curr = gcd(curr, nums[i + j]);
                   if (curr == 1) {
                       return nums.size() - 1 + m - 1 - oneCount;
                   }
               }
           }
        }
        return -1;
    }
};