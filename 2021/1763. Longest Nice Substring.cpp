class Solution {
public:
    string longestNiceSubstring(string s) {        
        string maxStr;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                bool found = true;
                vector<bool> lower(26, false), upper(26, false);
                for (int k = i; k <= j; k++) {
                    if (s[k] >= 'a' && s[k] <= 'z') {
                        lower[s[k] - 'a'] = true;
                    } else {
                        upper[s[k] - 'A'] = true;
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (lower[i] ^ upper[i]) {
                        found = false;
                        break;
                    }
                }
                if (found && (j - i + 1) > (int)(maxStr.length())) {
                    maxStr = s.substr(i, j - i + 1);
                }
            }
        }
        return maxStr;
    }
};