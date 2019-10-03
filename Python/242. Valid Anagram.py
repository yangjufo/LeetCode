from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        sCount = defaultdict(int)
        for c in s:
            sCount[c] += 1
        for c in t:
            sCount[c] -= 1
            if sCount[c] == 0:
                del sCount[c]        
        return len(sCount) == 0
