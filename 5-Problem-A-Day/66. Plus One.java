class Solution {
    public int[] plusOne(int[] digits) {
        int[] ans = new int[digits.length + 1];
        int carry = 1;
        for (int i = digits.length - 1; i > -1; i--) {
            int tmp = digits[i] + carry;
            ans[i + 1] = tmp % 10;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry != 0) {
            ans[0] = carry;
            return ans;
        } else
            return digits;
    }
}
