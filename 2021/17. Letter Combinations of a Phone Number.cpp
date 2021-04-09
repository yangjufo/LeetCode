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

class Solution {
public:
    unordered_map<char, string> digitLetterMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> combs = {""};
        for (char c : digits) {
            int size = combs.size();
            for (int i = 0; i < size; i++) {
                string curr = combs[i];
                for (int j = 0; j < digitLetterMap[c].length(); j++) {
                    if (j == 0) {
                        combs[i] += digitLetterMap[c][j];
                    } else {
                        combs.push_back(curr + digitLetterMap[c][j]);
                    }
                }
            }            
        }
        return combs;
    }
};