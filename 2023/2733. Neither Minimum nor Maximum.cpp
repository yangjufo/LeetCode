class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mi = 101, ma = 0;
        for (int n : nums) {
            mi = min(n, mi);
            ma = max(n, ma);
        }
        for (int n : nums) {
            if (n > mi && n < ma) {
                return n;
            }
        }
        return -1;
    }
};