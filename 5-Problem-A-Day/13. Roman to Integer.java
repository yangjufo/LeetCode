class Solution {
    public int romanToInt(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'M')
                ans += 1000;
            else if (c == 'D')
                ans += 500;
            else if (c == 'C') {
                if (i < s.length() - 1 && (s.charAt(i + 1) == 'D' || s.charAt(i + 1) == 'M'))
                    ans -= 100;
                else
                    ans += 100;
            } else if (c == 'L')
                ans += 50;
            else if (c == 'X') {
                if (i < s.length() - 1 && (s.charAt(i + 1) == 'L' || s.charAt(i + 1) == 'C'))
                    ans -= 10;
                else
                    ans += 10;
            } else if (c == 'V')
                ans += 5;
            else if (c == 'I') {
                if (i < s.length() - 1 && (s.charAt(i + 1) == 'V' || s.charAt(i + 1) == 'X'))
                    ans -= 1;
                else
                    ans += 1;
            }
        }
        return ans;
    }
}
