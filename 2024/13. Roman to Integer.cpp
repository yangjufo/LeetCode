class Solution {
public:
    unordered_map<char, int> ri = {{'M', 1000}, {'D', 500}, {'C', 100},
                                   {'L', 50},   {'X', 10},  {'V', 5},
                                   {'I', 1}};
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int flag = 1;
            if (i + 1 < s.length() &&
                ((s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) ||
                 (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                 (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')))) {
                flag = -1;
            }
            num += flag * ri[s[i]];
        }
        return num;
    }
};