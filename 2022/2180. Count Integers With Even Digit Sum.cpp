class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            int n = i, d = 0;
            while (n > 0) {
                d += n % 10;
                n /= 10;
            }
            if (d % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};