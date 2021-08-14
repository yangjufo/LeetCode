class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> row(26, 1);
        string row2("asdfghjkl");
        for (char c : row2) {
            row[c - 'a'] = 2;            
        }
        string row3("zxcvbnm");
        for (char c : row3) {
            row[c - 'a'] = 3;
        }
        vector<string> res;
        for (string& w : words) {
            int curr = row[tolower(w[0]) - 'a'], i = 1;
            while (i < w.length() && row[tolower(w[i]) - 'a'] == curr) {
                i++;
            }
            if (i >= w.length()) {
                res.push_back(w);
            }
        }
        return res;
    }
};