class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        int carry = b;
        int tmp;
        while (carry){
            tmp = sum;
            sum = tmp ^ carry;
            carry = (tmp & carry) << 1;
        }
        return sum;
    }
};