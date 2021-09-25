class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        int prev3 = 0, prev2 = 1, prev1 = 1;
        for (int i = 3; i <= n; i++) {
            int curr = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int p3 = 0, p2 = 1, p1 = 1;
        for (int i = 3; i <= n; i++) {
            int curr = p3 + p2 + p1;
            p3 = p2;
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};