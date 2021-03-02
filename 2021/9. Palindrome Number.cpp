class Solution {
public:
    bool isPalindrome(int x) {
        int reverse = 0, tmp = x;
        while (tmp > 0) {
            if ((tmp < 0 && reverse < (INT_MIN - tmp % 10) / 10)
               || (tmp > 0 && reverse > (INT_MAX - tmp % 10) / 10)) return false;
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        return reverse == x;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int reverse = 0;
        while (x > reverse) {            
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == x || x == reverse / 10;
    }
};