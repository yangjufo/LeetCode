class Solution {
    public double myPow(double x, int n) {
        if (n == Integer.MIN_VALUE) {
            double half = halfPow(1 / x, -n/2);
            return half * half;
        }            
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return halfPow(x, n);
    }
    
    private double halfPow(double x, int n) {
        if (n == 0)
            return 1.0;
        double half = halfPow(x, n /2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }        
}