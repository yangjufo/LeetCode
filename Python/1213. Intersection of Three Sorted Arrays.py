class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        i = j = k = 0
        ans = list()
        while i < len(arr1) and j < len(arr2) and k < len(arr3):            
            count = 0
            tmp = min(arr1[i], arr2[j], arr3[k])
            if arr1[i] == tmp:
                i += 1
                count += 1
            if arr2[j] == tmp:
                j += 1
                count += 1
            if arr3[k] == tmp:
                k += 1
                count += 1
            if count == 3:
                ans.append(arr1[i - 1])
        return ans