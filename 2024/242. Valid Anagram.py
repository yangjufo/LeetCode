class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_count = defaultdict(int)
        for c in s:
            s_count[c] += 1
        for c in t:
            s_count[c] -= 1
            if s_count[c] < 0:
                return False
        return True
