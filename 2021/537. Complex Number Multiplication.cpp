class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int split = num1.find('+');
        int left1 = stoi(num1.substr(0, split)), right1 = stoi(num1.substr(split + 1, (int)num1.length() - 1 - split));
        split = num2.find('+');
        int left2 = stoi(num2.substr(0, split)), right2 = stoi(num2.substr(split+ 1, (int)num2.length() - 1 - split));
        return to_string(left1 * left2 - right1 * right2) + "+" + to_string(left1 * right2 + left2 * right1) + "i";
    }
};

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int split = num1.find('+');
        int left1 = stoi(num1.substr(0, split)), right1 = stoi(num1.substr(split + 1, (int)num1.length() - 1 - split));
        split = num2.find('+');
        int left2 = stoi(num2.substr(0, split)), right2 = stoi(num2.substr(split+ 1, (int)num2.length() - 1 - split));
        return to_string(left1 * left2 - right1 * right2) + "+" + to_string(left1 * right2 + left2 * right1) + "i";
    }
};