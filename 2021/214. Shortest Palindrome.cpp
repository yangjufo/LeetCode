class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s.rbegin(), s.rend());
        string combined = s + '#' + rev;
        vector<int> table(combined.size(), 0);
        for (int i = 1; i < combined.size(); i++) {
            int j = table[i - 1];
            while (j > 0 && combined[j] != combined[i]) {
                j = table[j - 1];
            }
            if (combined[j] == combined[i]) {
                j++;
            }       
            table[i] = j;
        }
        return rev.substr(0, rev.size() - table[combined.size() - 1]) + s;
    }
};