class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& w : words) {
            string tmp(w);
            reverse(tmp.begin(), tmp.end());
            if (tmp == w) {
                return w;
            }
        }
        return "";
    }
};