class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        src = [[] for i in range(26)]
        for (i, c) in enumerate(source):
            src[ord(c) - ord('a')].append(i)            
        count = 1
        start = 0
        i = 0
        for i in range(len(target)):
            idx = src[ord(target[i])-ord('a')]
            if len(idx) == 0:
                return -1
            curr = bisect.bisect_left(idx, start)             
            if curr == len(idx):
                count += 1
                start = idx[0] + 1
            else:
                start = idx[curr] + 1              
        return count
                
