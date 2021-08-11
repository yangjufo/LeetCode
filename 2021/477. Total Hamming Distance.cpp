class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitCount(32, 0);
        for (int n : nums) {
            for (int i = 0; i < 32; i++) {
                bitCount[i] += (n & (1 << i)) == 0 ? 0 : 1;
            }
        }
        int total = 0, N = nums.size();
        for (int i = 0; i < 32; i++) {
            total += bitCount[i] * (N - bitCount[i]);
        }            
        return total;
    }
};