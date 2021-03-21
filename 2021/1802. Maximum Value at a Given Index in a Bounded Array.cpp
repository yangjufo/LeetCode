class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = maxSum / n, right = maxSum - (n - 1);
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canWork(n, index, maxSum, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return canWork(n, index, maxSum, left) ? left : left - 1;
    }
    
    bool canWork(long long n, long long index, long long maxSum, long long val) {
        long long sum = 0;
        if (val >= index + 1) {
            sum += (val - index + val) * (index + 1) / 2;
        } else {
            sum += (1 + val) * val / 2 + (index + 1- val); 
        }
        if (val >= n - index) {
            sum += (val - (n - 1 - index) + val - 1) * (n - 1 - index) / 2;
        } else {
            sum += (1 + val - 1) * (val - 1) / 2 + (n - index - val);
        }
        return sum <= maxSum;
    }
};