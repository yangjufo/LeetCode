class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        new_s = ""
        while new_s == "" and len(s) != 0:
            count = 1
            for i in range(1, len(s)):
                if s[i] == s[i - 1]:
                    count += 1
                else:
                    new_s += s[i - count % k:i]
                    count = 1
                if i == len(s) - 1:
                    new_s += s[i - count % k + 1:i + 1]
            if len(s) != len(new_s):
                s = new_s
                new_s = ""
        return new_s
