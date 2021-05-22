class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string word : words) {
            vector<int> w(26, -1), p(26, -1);
            int i = 0;
            for (;i < word.length(); i++) {
                int wi = word[i] - 'a', pi = pattern[i] - 'a';
                if (w[wi] == -1 && p[pi] == -1) {
                    w[wi] = p[pi] = i;
                } else if (w[wi] != p[pi]) {
                    break;
                }
            }
            if (i >= word.length()) {
                res.push_back(word);
            }
        }
        return res;
    }
};