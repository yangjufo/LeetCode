class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) return num;
        long res = 0, mul = 1;
        for (int i = 9; i >= 2; i--) {
            while (num % i == 0) {
                num /= i;
                res = mul * i + res;
                mul *= 10;
            }
        }
        return num < 2 && res <= INT_MAX ? (int) res : 0;
    }
};