class Solution {
public:
    vector<int> mem;
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& l, string& r) {
            return l.length() < r.length();
        });
        mem.resize(words.size(), -1);
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            dfs(words, i);
            res = max(res, mem[i]);
        }
        return res;
    }
    
    int dfs(vector<string>& words, int start) {
        if (mem[start] != -1) return mem[start];
        mem[start] = 1;
        for (int i = start; i < words.size(); i++) {
            if (isPre(words[start], words[i])) {
                mem[start] = max(mem[start], dfs(words, i) + 1);
            }
        }
        return mem[start];
    }
    
    bool isPre(string& word1, string& word2) {
        if (word1.length() + 1 != word2.length()) return false;
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length()) {
            if (word1[i] == word2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == word1.length();
    }
};