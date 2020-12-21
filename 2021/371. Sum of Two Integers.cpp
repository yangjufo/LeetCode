class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;
        
        while (b != 0) {            
            int answer = a ^ b;
            int carry = ((a & b) & mask) << 1;
            a = answer;
            b = carry;
        }
        return a;
    }
};