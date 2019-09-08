class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        maxEndHere = [arr[0]] * n
        maxStartHere = [arr[0]] * n
        ans = arr[0]
        maxEndHere[0] = arr[0]
        for i in range(1, n):
            maxEndHere[i] = max(arr[i], maxEndHere[i - 1] + arr[i])
            ans = max(ans, maxEndHere[i])
        maxStartHere[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            maxStartHere[i] = max(arr[i], maxStartHere[i + 1] + arr[i])
        for i in range(1, n - 1):
            ans = max(ans, maxEndHere[i - 1] + maxStartHere[i + 1])
        return ans
