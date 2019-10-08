class Solution:
    def checkRecord(self, s: str) -> bool:
        a_count = 0
        l_count = 0
        for c in s:
            if c == 'A':
                l_count = 0
                a_count += 1
            elif c == 'L':
                l_count += 1
            else:
                l_count = 0
            if a_count > 1 or l_count > 2:
                return False
        return True
