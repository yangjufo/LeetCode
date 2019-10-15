class Solution:
    
    def __init__(self):
        self.map = {}
    
    def diffWaysToCompute(self, input: str) -> List[int]:
        res = []
        for i, c in enumerate(input):
            if c == '+' or c == '-' or c == '*':
                left = self.map.get(input[:i], self.diffWaysToCompute(input[:i]))
                right = self.map.get(input[i + 1:], self.diffWaysToCompute(input[i + 1:]))   
                for l1 in left:
                    for l2 in right:
                        if c == '+':
                            r = l1 + l2
                        elif c == '-':
                            r = l1 - l2
                        elif c == '*':
                            r = l1 * l2
                        res.append(r)
        if len(res) == 0:
            res.append(int(input))
        self.map[input] = res
        return res
    
                
            