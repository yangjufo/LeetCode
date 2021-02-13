class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while (num > 0) {
            count++;
            if (num & 0x1 == 1) {
                num -= 1;
            } else {
                num >>= 1;
            }
        }
        return count;
    }
};