class Solution {
    public int myAtoi(String s) {
        int flag = 1;
        int ans = 0;
        boolean found = false;
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                found = true; 
                if (flag > 0 && ans > (Integer.MAX_VALUE - (c -'0')) / 10){
                    return Integer.MAX_VALUE;
                }
                if (flag < 0 && ans < (Integer.MIN_VALUE + (c - '0')) / 10) {
                    return Integer.MIN_VALUE;
                }
                ans = ans * 10 + flag * (c - '0');                                     
            } else {
                if (c == ' ') {
                    if (found) break;
                } else if (c == '-' || c == '+') {
                    if (found) break;
                    found = true;
                    flag = (c == '+') ? 1 : -1;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
}