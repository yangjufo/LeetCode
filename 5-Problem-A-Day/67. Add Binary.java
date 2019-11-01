class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        StringBuilder ans = new StringBuilder();
        while (i > -1 || j > -1) {
            int tmp = carry;
            if (i > -1)
                tmp += Character.getNumericValue(a.charAt(i));
            if (j > -1)
                tmp += Character.getNumericValue(b.charAt(j));
            if (tmp <= 1) {
                ans.append(Integer.toString(tmp));
                carry = 0;
            } else {
                ans.append(Integer.toString(tmp % 2));
                carry = 1;
            }n
            i -= 1;
            j -= 1;
        }
        if (carry > 0)
            ans.append(Integer.toString(carry));
        ans.reverse();
        return ans.toString();
    }
}
