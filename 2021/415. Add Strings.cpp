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

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int addOn = 0, i = (int)num1.length() - 1, j = (int)num2.length() - 1;
        while (i >= 0 || j >= 0) {
            int sum = addOn;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }       
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }            
            res += sum % 10 + '0';
            addOn = sum / 10;            
        }
        if (addOn > 0) {
            res += addOn + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }    
};