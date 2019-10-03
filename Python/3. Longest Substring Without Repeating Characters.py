class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        counter = set()
        start = 0
        length = 0
        for i in range(len(s)):            
            while s[i] in counter and start <= i:                   
                counter.remove(s[start])
                start += 1       
            counter.add(s[i])
            length = max(length, i - start + 1)
        return length
