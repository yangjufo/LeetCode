class Solution(object):
    def lengthOfLIS(self, nums):             
        record = {}
        ans = 0
        for num in nums:
            length = 1
            for k, v in record.items():
                if k < num and v + 1 > length:
                    length = v + 1
            record[num] = length
            ans = max(ans, length)
        return ans
                    