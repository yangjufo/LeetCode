class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = path.split('/')
        stack = list()
        ans = str()
        for d in dirs:
            if d == '.' or d == '':
                continue
            elif d == '..':
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(d)
        return '/' + '/'.join(stack)
