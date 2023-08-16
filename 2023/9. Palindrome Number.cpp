class Solution {
public:
    bool isPalindrome(int x) {
        std::string x_str = to_string(x);
        int i = 0, j = x_str.length() - 1;
        while (i < j) {
            if (x_str[i] != x_str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};