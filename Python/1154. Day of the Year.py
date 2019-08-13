class Solution:
    def dayOfYear(self, date: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        dates = date.split('-')
        year = int(dates[0])
        month = int(dates[1])
        day = int(dates[2])
        ans = 0
        if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
            days[1] = 29
        for i in range(0, month - 1):
            ans += days[i]
        return ans + day
