class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, swap = 0;
        for (char c : s) {
            if (c == ']') {
                close++;
            } else {
                open++;
            }
            if (close > open) {
                close--;
                open++;
                swap++;
            }
        }
        return swap;
    }
};