class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            tmp = destination
            destination = start
            start = tmp
        total_sum = clock_sum = 0
        for i in range(len(distance)):
            total_sum += distance[i]
            if i >= start and i < destination:
                clock_sum += distance[i]
        return min(clock_sum, total_sum - clock_sum)