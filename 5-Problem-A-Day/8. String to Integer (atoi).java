class Solution {
    public int myAtoi(String str) {
        int flag = 1;
        int ans = 0;
        boolean findNum = false;
        for (char c : str.toCharArray()) {
            if (c == ' ' && !findNum) 
                continue;            
            else if (c == '-' && !findNum){
                flag = -1;
                findNum = true;
            }
            else if (c == '+' && !findNum) {
                flag = 1;
                findNum = true;
            }
            else if (c >= '0' && c <= '9') {
                findNum = true;
                if (ans > 0 && ans > (Integer.MAX_VALUE - c + '0') / 10)
                    return Integer.MAX_VALUE;
                else if (ans < 0 && ans < (Integer.MIN_VALUE + c - '0') / 10)
                    return Integer.MIN_VALUE;                
                ans = ans * 10 + flag * (c - '0');
            }
            else
                return ans;
        }
        return ans;
    }
}
