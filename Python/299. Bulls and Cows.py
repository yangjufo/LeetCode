from collections import defaultdict
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        s_count = defaultdict(int)
        g_count = defaultdict(int)
        bulls = defaultdict(int)
        cows = 0
        for i in range(len(secret)):
            s_count[secret[i]] += 1
            g_count[guess[i]] += 1
            if secret[i] == guess[i]:
                bulls[secret[i]] += 1
        for k, v in s_count.items():
            cows += min(g_count[k], v) - bulls[k]
        return str(sum(bulls.values())) + "A" + str(cows) + "B"
