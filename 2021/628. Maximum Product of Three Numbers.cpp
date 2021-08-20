class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = 1001, min2 = 1001, max1 = -1001, max2 = -1001, max3 = -1001;
        for (int n : nums) {
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;                
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }            
        }
        if (min1 > 1000 || min2 > 1000 || max1 * max2 * max3 > min1 * min2 * max1) {
            return max1 * max2 * max3;
        }
        return min1 * min2 * max1;
    }
};