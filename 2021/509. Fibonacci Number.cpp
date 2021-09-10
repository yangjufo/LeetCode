class Solution {
public:
    int fib(int n) {        
        if (n == 0) return 0;        
        int prev1 = 0, prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = prev1 + prev2;
            prev1 = prev2;
            prev2 = tmp;
        }
        return prev2;
    }
};

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};