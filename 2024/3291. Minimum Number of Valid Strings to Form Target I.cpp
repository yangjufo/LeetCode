struct TrieNode {
    vector<TrieNode*> next;

    TrieNode() { next.resize(26, NULL); }

    TrieNode* Add(char c) {
        if (next[c - 'a'] == NULL) {
            next[c - 'a'] = new TrieNode();
        }
        return next[c - 'a'];
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    void add(string& w) {
        TrieNode* node = root;
        for (char c : w) {
            node = node->Add(c);
        }
    }

    vector<int> search(string& target, int start) {
        vector<int> valid_lengths;
        TrieNode* node = root;
        for (int i = start; i < target.length(); i++) {
            if (node->next[target[i] - 'a'] == NULL) {
                break;
            }
            node = node->next[target[i] - 'a'];
            valid_lengths.push_back(i - start + 1);

        }
        return valid_lengths;
    }

    int minValidStrings(vector<string>& words, string target) {
        for (string& w : words) {
            add(w);
        }
        vector<int> dp(target.length() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < target.length(); i++) {
            if (dp[i] == INT_MAX) {
                continue;
            }
            vector<int> lengths = search(target, i);
            for (int len : lengths) {
                dp[i + len] = min(dp[i + len], dp[i] + 1);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};