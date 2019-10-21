class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        s = list(s)
        counts = list()
        j = 0
        for i in range(len(s)):
            s[j] = s[i]
            if j == 0 or s[j] != s[j - 1]:
                counts.append(1)
            else:
                incremented = counts.pop() + 1
                if incremented == k:
                    j = j - k
                else:
                    counts.append(incremented)
            j += 1
        return ''.join(s[0:j])
                    
