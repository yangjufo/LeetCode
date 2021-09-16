class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row : image) {
            reverse(row.begin(), row.end());
            for (int& p : row) {
                p = p == 0 ? 1 : 0;
            }
        }
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res;
        for (vector<int>& row : image) {
            vector<int> newRow;
            for (int i = (int)row.size() - 1; i >= 0; i--) {
                newRow.push_back(row[i] == 1 ? 0 : 1);
            }
            res.push_back(newRow);
        }
        return res;
    }
};