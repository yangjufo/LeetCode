class MinStack:

    def __init__(self):
        self.stack_ = list()
        self.minStack_ = list()

    def push(self, val: int) -> None:
        self.stack_.append(val)
        if len(self.minStack_) == 0 or val <= self.minStack_[-1]:
            self.minStack_.append(val)

    def pop(self) -> None:
        top_val = self.top()
        self.stack_.pop()
        if top_val == self.minStack_[-1]:
            self.minStack_.pop()

    def top(self) -> int:
        return self.stack_[-1]

    def getMin(self) -> int:
        return self.minStack_[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
