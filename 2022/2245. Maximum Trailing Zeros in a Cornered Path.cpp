class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        vector<vector<vector<pair<int, int>>>> pre(grid.size(), vector<vector<pair<int, int>>>(grid[0].size(), vector<pair<int, int>>(4)));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                pre[i][j][0].first = getCount(grid[i][j], 2);
                pre[i][j][0].second = getCount(grid[i][j], 5);
                if (j > 0) {
                    pre[i][j][0].first += pre[i][j - 1][0].first;
                    pre[i][j][0].second += pre[i][j - 1][0].second;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                pre[i][j][1].first = getCount(grid[i][j], 2);
                pre[i][j][1].second = getCount(grid[i][j], 5);
                if (j + 1 < grid[0].size()) {
                    pre[i][j][1].first += pre[i][j + 1][1].first;
                    pre[i][j][1].second += pre[i][j + 1][1].second;
                }
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                pre[i][j][2].first = getCount(grid[i][j], 2);
                pre[i][j][2].second = getCount(grid[i][j], 5);
                if (i > 0) {
                    pre[i][j][2].first += pre[i - 1][j][2].first;
                    pre[i][j][2].second += pre[i - 1][j][2].second;
                }
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = grid.size() -  1; i >= 0; i--) {
                pre[i][j][3].first = getCount(grid[i][j], 2);
                pre[i][j][3].second = getCount(grid[i][j], 5);
                if (i + 1 < grid.size()) {
                    pre[i][j][3].first += pre[i + 1][j][3].first;
                    pre[i][j][3].second += pre[i + 1][j][3].second;
                }
            }
        }

        vector<vector<int>> comb = {{0, 2}, {0, 3}, {1, 2}, {1, 3}};
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                for (auto& iter : comb) {
                    res = max(res, min(pre[i][j][iter[0]].first + pre[i][j][iter[1]].first - getCount(grid[i][j], 2), pre[i][j][iter[0]].second + pre[i][j][iter[1]].second - getCount(grid[i][j], 5)));
                }
            }
        }
        return res;
    }

    int getCount(int num, int f) {
        int count = 0;
        while (num % f == 0) {
            count++;
            num /= f;
        }
        return count;
    }
};