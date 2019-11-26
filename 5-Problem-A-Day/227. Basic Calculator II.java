class Solution {
    public int calculate(String s) {
        if (s == null || s.length() == 0)
            return 0;
        int num = 0;
        char sign = '+';
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (Character.isDigit(ch))
                num = num * 10 + ch - '0';
            if ((!Character.isDigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (sign == '-')
                    stack.push(-num);
                if (sign == '+')
                    stack.push(num);
                if (sign == '*')
                    stack.push(stack.pop() * num);
                if (sign == '/')
                    stack.push(stack.pop() / num);
                sign = ch;
                num = 0;
            }
        }
        int ans = 0;
        for (int n : stack)
            ans += n;
        return ans;
    }
}
