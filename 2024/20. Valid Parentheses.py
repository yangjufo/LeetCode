class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        mapping = {
            '}': '{',
            ']': '[',
            ')': '('
        }
        for c in s:
            if c in mapping:
                if len(stack) == 0 or stack[-1] != mapping[c]:
                    return False
                else:
                    stack.pop()
            else:
                stack.append(c)
        return len(stack) == 0
