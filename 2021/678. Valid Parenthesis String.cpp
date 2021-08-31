class Solution {
public:
    bool checkValidString(string s) {
        if (!isValid(s, '(', ')')) {
            return false;
        }
        reverse(s.begin(), s.end());
        return isValid(s, ')', '(');
    }   
    
    bool isValid(string& s, char open, char close) {
        int openCount = 0, closeCount = 0, starCount = 0;        
        for (char c : s) {
            if (c == open) {
                openCount++;
            } else if (c == close) {
                closeCount++;
            } else {
                starCount++;
            }
            if (closeCount > openCount) {
                if (closeCount - openCount > starCount) {
                    return false;
                } else {
                    starCount -= closeCount - openCount;
                    openCount = closeCount;
                }                
            }
        }
        return closeCount + starCount >= openCount;
    }
};