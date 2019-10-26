class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;
        int dvd = Math.abs(dividend), dvs = Math.abs(divisor), ans = 0, x = 0;
        while (dvd - dvs >= 0) {
            for (x = 0; dvd - (dvs << x << 1) >= 0; x++);
            ans += 1 << x;
            dvd -= dvs << x;
        }
        return (dividend > 0) == (divisor > 0) ? ans : -ans;
    }
}
