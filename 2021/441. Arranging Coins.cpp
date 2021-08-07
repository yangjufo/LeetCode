class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if ((1 + mid) * mid / 2 > n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (1 + left) * left / 2 > n ? left - 1 : left;
    } 
};