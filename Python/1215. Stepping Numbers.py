class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        ld = len(str(low))
        hd = len(str(high))
        ans = list()
        one = list([1, 2, 3, 4, 5, 6, 7, 8, 9])
        if ld == 1:
            for j in range(0, 10):
                if low <= j <= high:
                    ans.append(j)
        for i in range(1, hd + 1):
            tmp_one = list()
            for num in one:
                last = num % 10
                if last - 1 >= 0:
                    tmp_num = num * 10 + last - 1
                    tmp_one.append(tmp_num)
                    if low <= tmp_num <= high:
                        ans.append(tmp_num)
                if last + 1 <= 9:
                    tmp_num = num * 10 + last + 1
                    tmp_one.append(tmp_num)
                    if low <= tmp_num <= high:
                        ans.append(tmp_num)
            one = tmp_one.copy()
        return ans
