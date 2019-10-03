class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(s, left, right):
            l = left
            r = right
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return r - l -1;
        start = end = 0
        for i in range(len(s)):
            len1 = expand(s, i, i)
            len2 = expand(s, i, i + 1)
            length = max(len1, len2)            
            if (length > end - start):
                start = i - (length - 1) // 2
                end = i + length//2
        return s[start:end + 1]
