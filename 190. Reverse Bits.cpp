class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         uint32_t res = 0;
        int i = 0;
        while(n > 0){
            i++;
            res = (res << 1) + n % 2;
            n /= 2;
        }
        while(i < 32){
            i++;
            res <<= 1;
        }

        return res;
    }
};