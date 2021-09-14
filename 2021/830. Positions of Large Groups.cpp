class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = 0;
        s += " ";
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                if (i - start >= 3) {
                    res.push_back({start, i - 1});
                }
                start = i;
            }
        }
        return res;
    }
};