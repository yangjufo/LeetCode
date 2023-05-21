class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> indexes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                indexes[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int r = indexes[arr[i]].first, c = indexes[arr[i]].second;
            row[r] += 1;
            col[c] += 1;
            if (row[r] == n || col[c] == m) {
                return i;
            }
        }
        return arr.size() - 1;
    }
};