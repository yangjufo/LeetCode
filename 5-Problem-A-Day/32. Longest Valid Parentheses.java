class Solution {
    public int longestValidParentheses(String s) {
        int open = 0, close = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(')
                open += 1;
            else
                close += 1;
            if (open == close)
                ans = Math.max(ans, close * 2);
            else if (close > open)
                open = close = 0;
        }
        open = close = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '(')
                open += 1;
            else
                close += 1;
            if (open == close)
                ans = Math.max(ans, open * 2);
            else if (open > close)
                open = close = 0;
        }
        return ans;
    }
}
