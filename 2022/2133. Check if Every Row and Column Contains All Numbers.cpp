class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<int> found(n + 1, false);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (found[matrix[i][j]] == false) {
                    found[matrix[i][j]] = true;
                    count++;
                }
            }
            if (count < n) {
                return false;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<int> found(n + 1, false);
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (found[matrix[i][j]] == false) {
                    found[matrix[i][j]] = true;
                    count++;
                }
            }
            if (count < n) {
                return false;
            }
        }
        return true;
    }
};