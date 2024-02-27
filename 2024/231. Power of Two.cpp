class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; i++) {
            if (n == (1 << i)) {
                return true;
            }
            if (n < (1 << i)) {
                break;
            }
        }
        return false;
    }
};