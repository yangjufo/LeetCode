class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_count = defaultdict(int)
        for c in magazine:
            magazine_count[c] += 1
        ransomNote_count = defaultdict(int)
        for c in ransomNote:
            ransomNote_count[c] += 1
        for c, count in ransomNote_count.items():
            if magazine_count[c] < count:
                return False
        return True
