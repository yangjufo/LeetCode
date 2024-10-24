class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }

    void backtrack(string& s, int start, vector<string>& curr, vector<vector<string>>& res) {
        if (start >= s.length()) {
            res.push_back(curr);
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
};