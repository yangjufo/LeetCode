class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        new_s = ""
        for i in range(len(S) - 1, -1, -1):
            if S[i] == '-':
                continue
            if len(new_s) % (K + 1) == K:
                new_s += '-'            
            new_s += S[i].upper()                    
        return ''.join(reversed(new_s))
