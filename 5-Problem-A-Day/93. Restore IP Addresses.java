class Solution {
    int n;
    String s;
    LinkedList<String> segments = new LinkedList<>();
    ArrayList<String> ans = new ArrayList<>();

    private boolean valid(String segment) {
        int m = segment.length();
        if (m > 3)
            return false;
        return (segment.charAt(0) != '0') ? (Integer.valueOf(segment) <= 255) : (m == 1);
    }

    private void update_ans(int curr) {
        String segment = s.substring(curr + 1, n);
        if (valid(segment)) {
            segments.add(segment);
            ans.add(String.join(".", segments));
            segments.removeLast();
        }
    }

    private void backtrack(int prev, int dots) {
        int max_pos = Math.min(n - 1, prev + 4);
        for (int curr = prev + 1; curr < max_pos; curr++) {
            String segment = s.substring(prev + 1, curr + 1);
            if (valid(segment)) {
                segments.add(segment);
                if (dots - 1 == 0)
                    update_ans(curr);
                else
                    backtrack(curr, dots - 1);
                segments.removeLast();
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        n = s.length();
        this.s = s;
        backtrack(-1, 3);
        return ans;
    }
}
