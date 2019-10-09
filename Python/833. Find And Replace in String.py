class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        taken = 0
        replace = dict()
        for i, idx in enumerate(indexes):
            if S[idx: idx + len(sources[i])] == sources[i]:
                for j in range(idx, idx + len(sources[i])):
                    taken |= 1 << j
                replace[idx] = targets[i]
        idx_set = set(indexes)
        new_s = ""
        for i in range(len(S)):
            if taken & (1 << i) == 0:
                new_s += S[i]
            elif i in idx_set:
                new_s += replace[i]
        return new_s
