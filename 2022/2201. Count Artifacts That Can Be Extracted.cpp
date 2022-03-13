class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        for (auto& d : dig) {
            grid[d[0]][d[1]] = true;
        }
        int count = 0;
        for (auto& a : artifacts) {
            bool found = true;
            for (int i = a[0]; i <= a[2] && found; i++) {
                for (int j = a[1]; j <= a[3] && found; j++) {
                    if (!grid[i][j]) {
                        found = false;
                    }
                }
            }
            if (found) {
                count++;
            }
        }
        return count;
    }
};