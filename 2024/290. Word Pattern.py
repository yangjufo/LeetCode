class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        p_map = defaultdict(int)
        s_map = defaultdict(int)
        for i in range(len(pattern)):
            if p_map[pattern[i]] != s_map[words[i]]:
                return False
            p_map[pattern[i]] = i + 1
            s_map[words[i]] = i + 1
        return True
