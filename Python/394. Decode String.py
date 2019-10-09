class Solution:
    def decodeString(self, s: str) -> str:
        num_stack = list()
        str_stack = list()
        curr = ""
        num = 0
        for c in s:
            if '0' <= c <= '9':
                num = num * 10 + int(c)
            elif c == '[':
                num_stack.append(num)
                str_stack.append(curr)
                curr = ""
                num = 0
            elif c == ']':
                tmp = curr
                curr = str_stack.pop()
                n = num_stack.pop()
                curr += tmp * n
            else:
                curr += c
        return curr
