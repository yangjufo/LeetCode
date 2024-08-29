class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> rows;
        vector<int> length;
        int row = 0, i = 0;
        while (i < words.size()) {
            string& w = words[i];
            if (row >= length.size()) {
                length.push_back(0);
                rows.push_back({});
            }
            if (length[row] + w.length() <= maxWidth) {
                rows[row].push_back(w);
                length[row] += w.length() + 1;
            } else if (length[row] + w.length() > maxWidth) {
                row += 1;
                i -= 1;
            }
            i += 1;
        }
        vector<string> res(rows.size());
        for (int i = 0; i < rows.size(); i++) {
            if (rows[i].size() == 1) {
                res[i] += rows[i][0] + string(maxWidth - rows[i][0].length(), ' ');
                continue;
            }
            int space = (maxWidth - length[i] + rows[i].size()) / (rows[i].size() - 1);
            int remain = (maxWidth - length[i] + rows[i].size()) - (rows[i].size() - 1) * space;
            if (i == rows.size() - 1) {
                space = 1;
                remain = 0;
            }
            for (int j = 0; j < rows[i].size(); j++) {
                res[i] += rows[i][j];
                if (j < rows[i].size() - 1) {
                    res[i] += string(space + (remain > 0 ? 1 : 0), ' ');
                }
                remain -= 1;
            }
            if (i == rows.size() - 1) {
                res[i] += string(maxWidth - length[i] + 1, ' ');
            }
        }
        return res;
    }
};