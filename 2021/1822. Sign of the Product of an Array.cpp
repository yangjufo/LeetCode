class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for (int n : nums) {
            if (n == 0) return 0;
            if (n < 0) product *= -1;
        }
        return product;
    }
};