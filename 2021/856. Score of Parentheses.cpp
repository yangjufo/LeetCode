class Solution {
public:
    int scoreOfParentheses(string S) {
        int score = 0, open = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                open++;
            } else {
                open--;
                if (S[i - 1] == '(') {
                    score += 1 << open;
                }
            }
        }
        return score;
    }
};

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> sStack;
        sStack.push(0);
        
        for (char c : S) {
            if (c == '(') {
                sStack.push(0);
            } else {
                int v = sStack.top();
                sStack.pop();
                int w = sStack.top();
                sStack.pop();
                sStack.push(w + max(2 * v, 1));
            }            
        }
        
        return sStack.top();
    }
};