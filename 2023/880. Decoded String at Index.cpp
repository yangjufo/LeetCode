class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                total *= s[i] - '0';
            } else {
                total++;
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            k %= total;
            if (k == 0 && isalpha(s[i])) {
                return s.substr(i, 1);
            }

            if (isdigit(s[i])) {
                total /= s[i] - '0';
            } else {
                total--;
            }
        }
        return "";
    }
};