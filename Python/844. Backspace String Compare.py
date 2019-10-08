class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        new_s = ""
        new_t = ""
        for i in range(len(S)):
            if S[i] == '#' and len(new_s) > 0:
                new_s = new_s[:-1]
            elif S[i] != '#':
                new_s += S[i]
        for i in range(len(T)):
            if T[i] == '#' and len(new_t) > 0:
                new_t = new_t[:-1]
            elif T[i] != '#':
                new_t += T[i]
        return new_s == new_t
