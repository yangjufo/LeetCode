class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long res = 0, sum = 0;
        for (int n : nums) {
            res |= n;
            sum += n;
            res |= sum;
        }
        return res;
    }
};