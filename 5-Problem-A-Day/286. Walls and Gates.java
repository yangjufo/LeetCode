class Solution {
    int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length, n = m == 0 ? 0 : rooms[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0)
                    dfs(rooms, m, n, i, j, 0);
            }
        }
    }

    private void dfs(int[][] rooms, int m, int n, int i, int j, int dis) {
        if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] == -1
                || (rooms[i][j] <= dis && dis != 0))
            return;
        rooms[i][j] = dis;
        for (int[] d : dir) {
            int x = i + d[0], y = j + d[1];
            dfs(rooms, m, n, x, y, dis + 1);
        }
    }
}
