class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1, width = 0;
        for (char c : s) {
            if (width + widths[c - 'a'] > 100) {
                line++;
                width = 0;
            }
            width += widths[c - 'a'];
        }
        return {line, width};
    }
};