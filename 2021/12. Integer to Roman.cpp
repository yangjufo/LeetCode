class Solution {
public:
    string intToRoman(int num) {
        string ans;
        if (num >= 1000) {
            ans += string(num / 1000, 'M');
            num %= 1000;
        }
        if (num >= 900) {
            ans += "CM";
            num -= 900;
        }
        if (num >= 500) {
            ans += "D";
            num -= 500;
        }
        if (num >= 400) {
            ans += "CD";
            num -= 400;
        }
        if (num >= 100) {
            ans += string(num / 100, 'C');
            num %= 100;
        }
        if (num >= 90) {
            ans += string("XC");
            num -= 90;
        }
        if (num >= 50) {
            ans += "L";
            num -= 50;
        }
        if (num >= 40) {
            ans += "XL";
            num -= 40;
        }
        if (num >= 10) {
            ans += string(num / 10, 'X');
            num %= 10;
        }
        if (num >= 9) {
            ans += string("IX");
            num -= 9;
        }
        if (num >= 5) {
            ans += "V";
            num -= 5;
        }
        if (num >= 4) {
            ans += "IV";
            num -= 4;
        }
        if (num >= 0) {
            ans += string(num, 'I');
        }
        return ans;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        if (num >= 1000) {
            roman += string(num / 1000, 'M');
            num %= 1000;
        }
        if (num >= 900) {
            roman += "CM";
            num -= 900;
        }
        if (num >= 500) {
            roman += "D";
            num -= 500;
        }
        if (num >= 400) {
            roman += "CD";
            num -= 400;
        }
        if (num >= 100) {
            roman += string(num / 100, 'C');
            num %= 100;
        }
        if (num >= 90) {
            roman += "XC";
            num -= 90;
        }
        if (num >= 50) {
            roman += "L";
            num -= 50;
        }
        if (num >= 40) {
            roman += "XL";
            num -= 40;
        }
        if (num >= 10) {
            roman += string(num / 10, 'X');
            num %= 10;
        }
        if (num >= 9) {
            roman += "IX";
            num -= 9;
        }
        if (num >= 5) {
            roman += "V";
            num -= 5;
        }
        if (num >= 4) {
            roman += "IV";
            num -= 4;
        }
        if (num > 0) {
            roman += string(num, 'I');
        }
        return roman;
    }
};