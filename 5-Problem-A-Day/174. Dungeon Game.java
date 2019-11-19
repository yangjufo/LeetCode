class Solution {
    public int calculateMinimumHP(int[][] dungeon) {  
        int m = dungeon.length;
        int n = dungeon[0].length;

        // hp[y][x]: min hp required to reach bottom right (P).

        // int[][] hp = new int[m + 1][n + 1];
        int[] hp = new int[n + 1];
        Arrays.fill(hp, Integer.MAX_VALUE);
        hp[n - 1] = 1;
        // for (int[] row : hp) Arrays.fill(row, Integer.MAX_VALUE);
        // hp[m][n - 1] = hp[m - 1][n] = 1;

        for (int y = m - 1; y >= 0; --y)
            for (int x = n - 1; x >= 0; --x)
                hp[x] = Math.max(1, Math.min(hp[x], hp[x + 1]) - dungeon[y][x]);

        return hp[0];
    }
}
