class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)
        lo = 1
        hi = 2 * (10 ** 9)
        ab = a * b // gcd(a, b)
        bc = b * c // gcd(b, c)
        ac = a * c // gcd(a, c)
        abc = a * bc // gcd(a, bc)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            cnt = mid//a + mid//b + mid//c - mid//ab - mid//bc - mid//ac + mid//abc
            if cnt < n:
                lo = mid + 1
            else:
                hi = mid
        return lo
        
        
        