class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1Map = dict()
        for a1 in arr1:
            if a1 not in arr1Map:
                arr1Map[a1] = 1
            else:
                arr1Map[a1] += 1
        res = list()
        for a2 in arr2:
            res += [a2] * arr1Map[a2]
            del(arr1Map[a2])
        left = sorted(arr1Map)
        for a2 in left:
            res += [a2] * arr1Map[a2]
        return res
