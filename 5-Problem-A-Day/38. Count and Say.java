class Solution {
    public String countAndSay(int n) {
        if (n == 0)
            return "";
        String ans = "1";
        for (int i = 2; i <= n; i++) {
            int count = 0;
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < ans.length(); j++) {
                if (j == 0 || ans.charAt(j) == ans.charAt(j - 1))
                    count += 1;
                else {
                    tmp.append(Integer.toString(count));
                    tmp.append(ans.charAt(j - 1));
                    count = 1;
                }
            }
            if (count != 0) {
                tmp.append(Integer.toString(count));
                tmp.append(ans.charAt(ans.length() - 1));
            }
            ans = tmp.toString();
        }
        return ans;
    }
}
