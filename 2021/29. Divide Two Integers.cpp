class Solution {
public:
    int divide(int dividend, int divisor) {        
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            if (divisor == 1) return INT_MIN;
            if ((divisor & 0x1) == 1) return divide(dividend + 1, divisor);
            return divide(dividend >> 1, divisor >> 1);
        }
        
        int flag = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
        
        long long dvd = labs(dividend), dvs = labs(divisor), res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        
        return flag * res;
    }
};