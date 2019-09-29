from collections import Counter 
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occur = Counter(arr)
        counts = set()
        for _, v in occur.items():
            if v in counts:
                return False
            counts.add(v)
        return True
        
        