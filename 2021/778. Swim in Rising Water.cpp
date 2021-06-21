class Solution
{
public:
    int n, moves[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>> &grid)
    {
        n = size(grid);
        int l = max(grid[0][0], grid[n - 1][n - 1]), r = n * n - 1, mid;
        bool vis[50][50]{};
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (solve(grid, vis, 0, 0, mid))
                r = mid - 1;
            else
                l = mid + 1;
            memset(vis, false, sizeof vis);
        }
        return l;
    }

    bool solve(vector<vector<int>> &grid, bool vis[][50], int i, int j, int w_lvl)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] > w_lvl)
            return false;
        if (i == n - 1 && j == n - 1)
            return true;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
            if (solve(grid, vis, i + moves[k][0], j + moves[k][1], w_lvl))
                return true;
        return false;
    }
};