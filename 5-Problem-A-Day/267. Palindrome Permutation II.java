class Solution {
    Set<String> set = new HashSet<>();

    public List<String> generatePalindromes(String s) {
        int[] map = new int[128];
        char[] st = new char[s.length() / 2];
        if (!canPalindromes(s, map))
            return new ArrayList<>();
        char ch = 0;
        int k = 0;
        for (int i = 0; i < map.length; i++) {
            if (map[i] % 2 == 1)
                ch = (char) i;
            for (int j = 0; j < map[i] / 2; j++)
                st[k++] = (char) i;
        }
        permute(st, 0, ch);
        return new ArrayList<String>(set);
    }

    private boolean canPalindromes(String s, int[] map) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
            if (map[s.charAt(i)] % 2 == 0)
                count--;
            else
                count++;
        }
        return count <= 1;
    }

    private void swap(char[] s, int i, int j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    private void permute(char[] s, int l, char ch) {
        if (l == s.length)
            set.add(new String(s) + (ch == 0 ? "" : ch)
                    + new StringBuffer(new String(s)).reverse());
        else {
            for (int i = l; i < s.length; i++) {
                if (s[l] != s[i] || l == i) {
                    swap(s, l, i);
                    permute(s, l + 1, ch);
                    swap(s, l, i);
                }
            }
        }
    }
}
