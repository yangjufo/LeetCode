class Solution {
public:
    string largestOddNumber(string num) {
        int end = num.length() - 1;
        while (end >= 0 && (int)(num[end] - '0') % 2 == 0) {
            end--;
        }
        return num.substr(0, end + 1);
    }
};