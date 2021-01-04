class Solution {
public:
    string addStrings(string num1, string num2) {
        int left = num1.length() - 1, right = num2.length() - 1;
        string sum;
        int carry = 0;
        while (left >= 0 || right >= 0 || carry > 0) {
            int tmp = carry;
            if (left >= 0) {
                tmp += num1[left] - '0';
                left--;
            }
            if (right >= 0) {
                tmp += num2[right] - '0';
                right--;
            }
            sum += (tmp % 10) + '0';
            carry = tmp / 10;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};