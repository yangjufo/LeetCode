class Solution {
public:
    unordered_map<char, vector<char>> digitMap = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
    
    vector<string> letterCombinations(string digits) {        
        vector<string> res;
        backtrack(digits, 0, "", res);
        return res;
    }
    
    void backtrack(string& digits, int index, string current, vector<string>& res) {
        if (index == digits.length() && index != 0) {
            res.push_back(current);
            return;
        }
        for (char c : digitMap[digits[index]]) {
            backtrack(digits, index + 1, current + c, res);
        }
    }
};