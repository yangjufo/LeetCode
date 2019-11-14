class Solution {
    public int evalRPN(String[] tokens) {
        if (tokens.length == 0)
            return 0;
        Stack<Integer> nums = new Stack<>();
        for (String t : tokens) {
            if (t.equals("+") || t.equals("-") || t.equals("*") || t.equals("/")) {
                int n2 = nums.pop(), n1 = nums.pop();
                int ans = 0;
                if (t.equals("+"))
                    ans = n1 + n2;
                else if (t.equals("-"))
                    ans = n1 - n2;
                else if (t.equals("*"))
                    ans = n1 * n2;
                else
                    ans = n1 / n2;
                nums.push(ans);
            } else
                nums.push(Integer.valueOf(t));
        }
        return nums.pop();
    }
}
