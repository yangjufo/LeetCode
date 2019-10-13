class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = 0
        ans = 0
        for c in s:
            if c == 'L':
                count -= 1
            else:
                count += 1
            if count == 0:
                ans += 1
        return ans