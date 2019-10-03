from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tCount = defaultdict(int)
        for c in t:
            tCount[c] += 1
        mark = len(t)
        start = 0
        minLen = len(s) + 1
        minString = ""
        for i in range(len(s)):            
            tCount[s[i]] -= 1
            if tCount[s[i]] >= 0:
                mark -= 1            
            while mark == 0 and start <= i:                                             
                if i - start + 1 < minLen:
                    minLen = i - start + 1
                    minString = s[start:i+1]
                tCount[s[start]] += 1
                if tCount[s[start]] > 0:
                    mark += 1        
                start += 1
        return minString
                
