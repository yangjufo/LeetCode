class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        wordMark = [False] * (len(s) + 1)
        wordMark[0] = True
        for i in range(1, len(s) + 1):
            for j in range(0, i):
                if wordMark[j] and s[j:i] in wordSet:
                    wordMark[i] = True
                    break
        return wordMark[len(s)]
