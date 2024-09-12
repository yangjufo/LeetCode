class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_map = defaultdict(int)
        t_map = defaultdict(int)
        for i in range(len(s)):
            if s_map[s[i]] != t_map[t[i]]:
                return False
            s_map[s[i]] = i + 1
            t_map[t[i]] = i + 1
        return True
