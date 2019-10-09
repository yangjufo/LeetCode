from collections import defaultdict


class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time = defaultdict(list)
        self.value = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.time[key].append(timestamp)
        self.value[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        idx = bisect.bisect_right(self.time[key], timestamp)
        if idx == 0:
            return ""
        return self.value[key][idx - 1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
