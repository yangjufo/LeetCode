class Solution:
    def expand(self, S: str) -> List[str]:
        ans = []
        start = -1
        for i in range(len(S)):
            if S[i] == '{':
                start = i + 1
            elif S[i] == '}':
                chars = sorted(S[start:i].split(',')) 
                if len(ans) == 0:
                    ans = chars
                else:
                    new_ans = []
                    for an in ans.copy():
                        for c in chars:
                            new_ans.append(an + c)
                    ans = new_ans.copy()
                start = -1
            elif start == -1:
                if len(ans) == 0:
                    ans = [S[i]]
                else:                    
                    for j in range(len(ans)):
                        ans[j] += S[i]              
        return ans
                    
