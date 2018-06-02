class Solution {
public:
    bool isPalindrome(int x) {        
        if (x < 0)
            return false;
        int count = 1;
        int num = x;
        int first, last;
        while (num >= 10){
            count *= 10;
            num = num / 10;
        }
        while(x > 0){
            first = x / count;
            last = x % 10;
            if (first != last)
                return false;            
            x = x % count / 10;
            count /= 100;
        }
        return true;
    }
};