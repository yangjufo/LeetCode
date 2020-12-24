class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid > mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return (x / left == left) ? left : left - 1;
    }
};