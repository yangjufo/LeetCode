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

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (x - 1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};