class Solution:
    def numDecodings(self, s: str) -> int:
        ways = [0] * (len(s) + 1)
        ways[0] = 1
        for i in range(1, len(s) + 1):
            c = s[i - 1]
            if c >= '1' and c <= '9':
                ways[i] = ways[i - 1]
            if i > 1 and ((c >= '0' and c <= '9' and s[i - 2] == '1') or (c >= '0' and c <= '6' and s[i - 2] == '2')):
                ways[i] += ways[i - 2]
            if c == '0' and s[i - 2] != '1' and s[i - 2] != '2':
                return 0
        return 0 if len(s) == 0 else ways[len(s)]
