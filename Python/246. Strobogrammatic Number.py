class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        pairs = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}
        left = 0
        right = len(num) - 1
        while left <= right:
            if num[left] not in  pairs or num[right] not in pairs:
                return False
            if pairs[num[left]] != num[right]:
                return False
            left += 1
            right -= 1
        return True