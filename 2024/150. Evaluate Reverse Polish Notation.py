class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def cal(nums, op):
            num2 = nums[-1]
            nums.pop()
            num1 = nums[-1]
            nums.pop()
            if op == '+':
                nums.append(num1 + num2)
            elif op == '-':
                nums.append(num1 - num2)
            elif op == '*':
                nums.append(num1 * num2)
            elif op == '/':
                nums.append(int(num1 / num2))
        nums = list()
        for t in tokens:
            if t == '+' or t == '-' or t == '*' or t == '/':
                cal(nums, t)
            else:
                nums.append(int(t))
        return nums[-1]
