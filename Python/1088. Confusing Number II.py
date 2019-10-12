class Solution:
    def confusingNumberII(self, N: int) -> int:
        pairs = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}                
        def count(c):
            res = 0
            for k, v in pairs.items():
                if k < c:
                    res += 1
            return res
        def findTotal(s):
            if len(s) == 0:
                return 1
            first = s[0]
            res = count(first) * (int)(5**(len(s) - 1))
            if first in pairs:
                res += findTotal(s[1:])
            return res
        def dfs(curr, num, left, right):
            res = 0
            if left > right:
                s = ''.join(curr)
                if len(s) < len(num) or s < num:
                    res += 1
            else:
                for k, v in pairs.items():
                    curr[left] = k
                    curr[right] = v
                    if curr[0] == '0' and len(curr) > 1 or left == right and k != v:
                        continue
                    res += dfs(curr, num, left + 1, right - 1)
            return res
        
        num = str(N)
        ans = findTotal(num)
        for i in range(1, len(num) + 1):
            curr = ['0'] * i
            ans -= dfs(curr, num, 0, i - 1)
        return ans