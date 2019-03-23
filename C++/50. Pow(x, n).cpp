class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == INT_MIN)
        {
            x = 1 / x;
            return x * pow(x, INT_MAX);
        }
        if (n < 0){
            n = -n;
            x = 1/x;
        }
        return (n % 2 == 0) ? pow(x*x, n / 2) : x*pow(x*x, n / 2);
            
    }
};