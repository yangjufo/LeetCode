class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> count(26, 0), t(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c: target) {
            t[c - 'a']++;
        }
        int res = 100;
        for (int i = 0; i < 26; i++) {
            if (t[i] == 0) continue;
            res = min(res, count[i] / t[i]);
        }
        return res;
    }
};