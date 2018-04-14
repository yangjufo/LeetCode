class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT32_MIN){
            if(divisor == -1) return INT32_MAX;
            else if(divisor == 1)  return dividend;
            else return ((divisor&1) == 1) ? divide(dividend+1,divisor) : divide(dividend>>1, divisor>>1);         
            if(divisor == INT32_MIN) return 0;      
        }
        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);   
        long long res = 0;
        while (dvd >= dvs){
            long long temp = dvs, multiple = 1;
            while(dvd >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return flag == -1 ? 0 - res : res;               
    }
};