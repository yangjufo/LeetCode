class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<int> sum(grid[0].size());
        for (int j = 0; j < grid[0].size(); j++) {
            sum[j] = grid[0][j];
        }
        for (int i = 1; i < grid.size(); i++) {
            vector<int> tmp(grid[i].size());
            for (int j = 0; j < grid[i].size(); j++) {
                int currMin = INT_MAX;
                for (int k = 0; k < grid[i].size(); k++) {
                    currMin = min(currMin, sum[k] + grid[i][j] + moveCost[grid[i - 1][k]][j]);
                }
                tmp[j] = currMin;
            }
            sum = tmp;
        }
        int res = INT_MAX;
        for (int s : sum) {
            res = min(s, res);
        }
        return res;
    }
};