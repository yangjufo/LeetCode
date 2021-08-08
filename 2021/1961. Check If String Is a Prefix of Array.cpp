class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0, j = 0;
        while (i < s.length() && j < words.size()) {
            int k = 0;
            while (i < s.length() && k < words[j].length() && s[i] == words[j][k]) {
                i++;
                k++;
            }
            if (k < words[j].length()) return false;
            j++;        
        }
        return i >= s.length();
    }
};