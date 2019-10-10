class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def merge_sort(enum):
            half = len(enum) // 2
            if half:
                left, right = merge_sort(enum[:half]), merge_sort(enum[half:])
                m, n = len(left), len(right)
                i = j = 0                
                while i < m or j < n:                    
                    if j == n or i < m and left[i][1] <= right[j][1]:
                        enum[i + j] = left[i]
                        smaller[left[i][0]] += j
                        i += 1
                    else:
                        enum[i + j] = right[j]
                        j += 1
            return enum
        smaller = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return smaller
                    
                    
