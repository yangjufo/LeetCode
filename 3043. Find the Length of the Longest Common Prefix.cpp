struct TrieNode {
    vector<TrieNode*> next;

    TrieNode() {
        next.resize(10, NULL);
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* a1Root = new TrieNode();
        for (int a : arr1) {
            TrieNode* node = a1Root;
            for (char c : to_string(a)) {
                if (node->next[c - '0'] == NULL) {
                    node->next[c - '0'] = new TrieNode();
                }
                node = node->next[c - '0'];
            }
        }
        int maxLen = 0;
        for (int a : arr2) {
            TrieNode* node = a1Root;
            int len = 0;
            for (char c : to_string(a)) {
                if (node->next[c - '0'] == NULL) {
                    break;
                }
                node = node->next[c - '0'];
                len += 1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};