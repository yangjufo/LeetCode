from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start = 0
        counter = defaultdict(int)
        maxCount = 0
        maxLength = 0
        for i in range(len(s)):
            counter[s[i]] += 1
            maxCount = max(maxCount, counter[s[i]])
            if i - start + 1 - maxCount > k:
                counter[s[start]] -= 1
                start += 1            
            maxLength = max(i - start + 1, maxLength)
        return maxLength
