class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        string res;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j -= 1;
            }
            res += (sum % 10) + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};