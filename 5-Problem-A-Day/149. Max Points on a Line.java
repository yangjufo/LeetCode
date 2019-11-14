class Solution {
    public int maxPoints(int[][] points) {
        int l = points.length;
        if (l == 0)
            return 0;
        if (l <= 2)
            return l;

        int ans = 0;
        for (int i = 0; i < l - 1; i++) {
            Map<String, Integer> map = new HashMap<>();
            int overlap = 0, lineMax = 0;
            for (int j = i + 1; j < l; j++) {
                int x = points[i][0] - points[j][0], y = points[i][1] - points[j][1];
                if (x == 0 && y == 0)
                    overlap++;
                else {
                    int gcd = generateGcd(x, y);
                    x /= gcd;
                    y /= gcd;
                    String slope = String.valueOf(x) + String.valueOf(y);
                    int count = map.getOrDefault(slope, 0) + 1;
                    map.put(slope, count);
                    lineMax = Math.max(lineMax, count);
                }
            }
            ans = Math.max(ans, lineMax + overlap + 1);
        }
        return ans;
    }

    private int generateGcd(int x, int y) {
        if (y == 0)
            return x;
        return generateGcd(y, x % y);
    }
}
