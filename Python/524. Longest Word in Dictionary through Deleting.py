class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        def isSubsequence(x, y):
            i = j = 0
            while i < len(x) and j < len(y):
                if x[i] == y[j]:
                    i += 1
                j += 1
            return i == len(x)
        max_str = ""
        for ds in d:
            if isSubsequence(ds, s):
                if len(ds) > len(max_str) or len(ds) == len(max_str) and ds < max_str:
                    max_str = ds
        return max_str
            