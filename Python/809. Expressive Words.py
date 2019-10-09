class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:        
        def RLE(S):
            counts = list()
            prev = -1
            key = ""
            for i in range(len(S)):
                if i == len(S) - 1 or S[i] != S[i + 1]:
                    key += S[i]
                    counts.append(i - prev)
                    prev = i
            return key, counts
        RS, SC = RLE(S)
        ans = 0
        for word in words:
            RW, WC = RLE(word)
            find = True
            if RS != RW:
                continue
            for i in range(len(RS)):
                if SC[i] < 3 and SC[i] != WC[i] or SC[i] < WC[i]:
                    find = False
                    break
            ans += 1 if find else 0
        return ans
            
                
