class Solution {
public:
    int binaryGap(int n) {
        int last1 = -1, maxDis = 0;
        int index = 32;
        while (n > 0) {
            if ((n & 0x1) == 1) {
                maxDis = max(last1 - index, maxDis);
                last1 = index;
            }
            index--;
            n >>= 1;
        }
        return maxDis;
    }
};