class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {        
        int factor[200001];
        fill(factor, factor+ 200001, 0);
        for (int i = 0; i < nums.size(); ++i) {        	
            for (int j = 1; j * j <= nums[i]; ++j) {
                if (nums[i] % j == 0) {
                    int factor1 = j;
                    int factor2 = nums[i] / j;

                    if (factor[factor1] == 0) {
                        factor[factor1] = nums[i];
                    } else {
        				// Find gcd of all nums[i] with factor1
                        factor[factor1] = gcd(factor[factor1], nums[i]);
                    }

                    if (factor[factor2] == 0) {
        				// Find gcd of all nums[i] with factor2
                        factor[factor2] = nums[i];
                    } else {
                        factor[factor2] = gcd(factor[factor2], nums[i]);
                    }
                }

            }
        }
        int ans = 0;
        // Check if all factors of i form a GCD of i or not.
        for (int i = 1; i <= 200000; ++i ) if (factor[i] == i) ++ans;
        return ans;
    }
};