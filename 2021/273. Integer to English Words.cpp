class Solution {
public:
    string zero2nine[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string ten2nineteen[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string twenty2ninety[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string numberToWords(int num) {
        string ans;
        if (num >= 1000000000) {
            ans += numberToWords(num / 1000000000) + " Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            ans += numberToWords(num / 1000000) + " Million ";
            num %= 1000000;
        }
        if (num >= 1000) {
            ans += numberToWords(num / 1000) + " Thousand ";
            num %= 1000;
        }
        if (num >= 100) {
            ans += numberToWords(num / 100) + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            ans += twenty2ninety[num / 10] + " ";
            num %= 10;
        }
        if (num >= 10) {
            ans += ten2nineteen[num - 10] + " ";
            num = 0;
        }
        if (num > 0) {
            ans += zero2nine[num] + " ";
        }
        return ans.empty() ? "Zero" : ans.substr(0, ans.length() - 1);
    }
};