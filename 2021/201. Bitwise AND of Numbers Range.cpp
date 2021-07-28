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

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // find the common 1-bits
        while (left < right) {
          left >>= 1;
          right >>= 1;
          ++shift;
        }
        return left << shift;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
         while (left < right) {
            // turn off rightmost 1-bit
            right = right & (right - 1);
        }
        return left & right;
    }
};