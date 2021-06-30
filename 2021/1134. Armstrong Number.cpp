class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0, len = to_string(n).length(), original = n;
        while (n > 0 && sum <= original) {
            sum += (int)pow(n % 10, len);
            n /= 10;        
        }
        return sum == original;
    }
};