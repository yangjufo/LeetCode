class Solution {
public:
    bool isPowerOfFour(int n) {
       while (n > 0) {
           if (n % 4 == 0) {
               n /= 4;
           } else {
               break;
           }
       }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
      return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0xaaaaaaaa) == 0);
    }
};