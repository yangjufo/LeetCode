class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<vector<bool>> top(50, vector<bool>(50, false)), left(50, vector<bool>(50, false)), right(50, vector<bool>(50, false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                top[i][j] = true;
                for (int k = 0; k < grid[i][j]; k++) {
                    left[i][k] = true;
                    right[j][k] = true;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {                
                sum += top[i][j] + left[i][j] + right[i][j];
            }
        }
        return sum;
    }
};