class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            next = 0
            while n != 0:
                next += (int)(n % 10) ** 2
                n /= 10
            n = next
        return n == 1
