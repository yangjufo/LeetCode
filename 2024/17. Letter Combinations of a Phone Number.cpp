class Solution {
public:
    unordered_map<char, vector<char>> cm = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ret = {""};
        for (char d : digits) {
            vector<string> curr;
            for (char c : cm[d]) {
                for (string& cu : ret) {
                    curr.push_back(cu + c);
                }
            }
            ret = curr;
        }
        return ret;
    }
};