class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        queen_set = set([(q[0], q[1]) for q in queens])
        direction = [(-1, -1), (0, -1), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (-1, 0)]
        ans = list()
        for d in direction:
            start = king.copy()
            while start[0] >=0 and start[0] < 8 and start[1] >= 0 and start[1] < 8:
                if (start[0], start[1]) in queen_set:
                    ans.append([start[0], start[1]])
                    break
                start[0] += d[0]
                start[1] += d[1]            
        return ans