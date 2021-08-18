class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = calStep(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                k--;
                curr *= 10;
            }
        }
        return curr;
    }
    
    int calStep(int n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n2, (long)n + 1) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};