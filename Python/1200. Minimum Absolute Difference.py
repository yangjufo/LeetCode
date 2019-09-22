class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        dis = {}
        minDis = 1000001
        for i in range(1, len(arr)):
            tmp = arr[i] - arr[i - 1]
            minDis = min(minDis, tmp)
            if tmp not in dis:
                dis[tmp] = list()
            dis[tmp].append([arr[i - 1], arr[i]])
        if minDis in dis:
            return dis[minDis]
        return []
            