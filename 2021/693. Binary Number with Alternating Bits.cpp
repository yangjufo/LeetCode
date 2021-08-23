class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n > 0) {            
            if (prev != -1 && (prev == (n & 0x1))) {
                return false;
            }
            prev = (n & 0x1);
            n >>= 1;
        }
        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long tmp = n ^ (n >> 1);
        return (tmp & tmp + 1) == 0;
    }
};