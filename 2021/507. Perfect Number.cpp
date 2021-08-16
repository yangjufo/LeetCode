class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= num / i; i++) {
            if (num % i == 0) {
                if (i != 1) {
                    sum += num / i;
                }
                if (i != num / i) {
                    sum += i;
                }                
            }            
        }
        return sum == num;
    }
};