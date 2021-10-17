class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        tokens = s.split(' ')
        prev = 0
        for t in tokens:
            if t[0] >= '0' and t[0] <= '9':
                curr = int(t)
                if curr <= prev:
                    return False
                prev = curr
        return True