class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count_map = {}
        for pair in dominoes:
            if tuple(pair) in count_map:
                count_map[tuple(pair)] += 1
            elif tuple([pair[1], pair[0]]) in count_map:
                count_map[tuple([pair[1], pair[0]])] += 1
            else:
                count_map[tuple(pair)] = 1
        count = 0
        for _, value in count_map.items():
            count += value * (value - 1) // 2
        return count      
            
                