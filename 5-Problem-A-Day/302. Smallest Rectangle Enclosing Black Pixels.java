class Solution {
    int top, bottom, left, right;
    int[][] dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    public int minArea(char[][] image, int x, int y) {
        top = image.length;
        left = image[0].length;
        bottom = right = -1;
        dfs(image, x, y);
        return (bottom - top + 1) * (right - left + 1);
    }

    private void dfs(char[][] image, int i, int j) {
        image[i][j] = '0';
        left = Math.min(j, left);
        right = Math.max(j, right);
        top = Math.min(i, top);
        bottom = Math.max(i, bottom);
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0], y = j + dir[k][1];
            if (x < 0 || x >= image.length || y < 0 || y >= image[0].length || image[x][y] != '1')
                continue;
            dfs(image, x, y);
        }
    }
}
