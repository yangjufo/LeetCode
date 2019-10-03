class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        for k in [A[0], B[0]]:
            rA = 0
            rB = 0
            find = True
            for i in range(len(A)):
                if A[i] != k and B[i] != k:
                    find = False
                    break
                elif A[i] != k:
                    rA += 1
                elif B[i] != k:
                    rB += 1
            if find:
                return min(rA, rB)
        return -1
