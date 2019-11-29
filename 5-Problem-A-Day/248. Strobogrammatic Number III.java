class Solution {
    char[][] pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    private int dfs(String low, String high, char[] c, int left, int right) {
        if (left > right) {
            String s = new String(c);
            if ((s.length() == low.length() && s.compareTo(low) < 0)
                    || (s.length() == high.length() && s.compareTo(high) > 0))
                return 0;
            return 1;
        }
        int count = 0;
        for (char[] p : pairs) {
            c[left] = p[0];
            c[right] = p[1];
            if (c.length != 1 && c[0] == '0')
                continue;
            if (left == right && p[0] != p[1])
                continue;
            count += dfs(low, high, c, left + 1, right - 1);
        }
        return count;
    }

    public int strobogrammaticInRange(String low, String high) {
        if (low == null || high == null || low.length() > high.length()
                || (low.length() == high.length() && low.compareTo(high) > 0))
            return 0;
        int count = 0;
        for (int len = low.length(); len <= high.length(); len++)
            count += dfs(low, high, new char[len], 0, len - 1);
        return count;
    }
}
