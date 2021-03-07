class Solution {
public:    
    int minimumLengthEncoding(vector<string>& words) {
        int count = 0;
        vector<bool> removed(words.size(), false);
        sort(words.begin(), words.end(), [](string& left, string& right) {
           return left.length() > right.length(); 
        });
        for (int i = 0; i < words.size(); i++) {
            count += words[i].length() + 1;
            if (removed[i]) continue;
            for (int j = i + 1; j < words.size(); j++) {
                if (removed[j]) continue;
                if (equal(words[j].rbegin(), words[j].rend(), words[i].rbegin())) {                    
                    removed[j] = true;
                    count -= words[j].length() + 1;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        for (string word : words) {
            for (int k = 1; k < word.length(); k++) {
                wordSet.erase(word.substr(k));
            }
        }
        int count = 0;
        for (string word : wordSet) {
            count += word.length() + 1;
        }
        return count;
    }
};

class TrieNode {
public:
    TrieNode* children[26];
    int count;
    
    TrieNode() {
        count = 0;        
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    } 
    
    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        unordered_map<TrieNode*, int> nodes;
        
        for (int i = 0; i < words.size(); i++) {
            TrieNode* curr = root;
            for (int j = words[i].length() - 1; j >= 0; j--) {                
                curr = curr->get(words[i][j]);
            }
            nodes[curr] = i;
        }
        
        int count = 0;
        for (auto iter : nodes) {
            if (iter.first->count == 0) {
                count += words[iter.second].length() + 1;
            }
        }
        return count;
    }
};