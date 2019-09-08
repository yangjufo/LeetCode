import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        ans = datetime.date(year, month, day)
        return ans.strftime("%A")