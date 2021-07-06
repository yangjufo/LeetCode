class Solution {
public:
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                right = (left == 0) ? right + 1: right;
                left = (left > 0) ? left - 1 : left;
            }
        }
        backtrack(s, 0, 0, 0, left, right, "");
        return vector<string>(res.begin(), res.end());
    }
    
    void backtrack(string& s, int index, int leftCount, int rightCount, int leftRem, int rightRem, string curr) {        
        if (index >= s.length()) {
            if (leftRem == 0 && rightRem == 0) {
                res.insert(curr);
            }
            return;
        }
        if ((s[index] == '(' && leftRem > 0) || (s[index] == ')' && rightRem > 0)) {
            backtrack(s, index + 1, leftCount, rightCount, leftRem - (s[index] == '(' ? 1 : 0), rightRem - (s[index] == ')' ? 1 : 0), curr);
        }
        curr += s[index];
        if (s[index] != '(' && s[index] != ')') {
            backtrack(s, index + 1, leftCount, rightCount, leftRem, rightRem, curr);
        } else if (s[index] == '(') {
            backtrack(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, curr);
        } else if (rightCount < leftCount) {
            backtrack(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, curr);
        }
        curr.pop_back();
    }
};