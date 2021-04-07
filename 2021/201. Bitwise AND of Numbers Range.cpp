class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = INT_MAX;
        for (int i = left; i < right && ans != 0; i++) {
            ans &= i;
        }
        ans &= right;
        return ans;
    }
};