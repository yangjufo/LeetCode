class Solution {
public:    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int N = s.length();        
        vector<vector<string>> candidates(N + 1, vector<string>());
        candidates[0].push_back("");
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end() && !candidates[j].empty()) {
                    for (string& can : candidates[j]) {                        
                        candidates[i + 1].push_back((j == 0 ? "" : can + " ") + s.substr(j, i - j + 1));
                    }
                }
            }
        }        
        return candidates[N];
    }        
};

class Solution {
public:
    unordered_map<string, vector<string>> mem;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return backtrack(s, wordDict);
    }
    
    vector<string> backtrack(string s, vector<string>& wordDict) {
        if (mem.find(s) != mem.end()) {
            return mem[s];
        }
        if (s.empty()) {
            return {""};
        }
        
        vector<string> curr;
        
        for (string& word : wordDict) {
            if (s.find(word) == 0) {
                vector<string> sublist = backtrack(s.substr(word.length()), wordDict);
                for (string& sub : sublist) {
                    curr.push_back(word + (sub.empty() ? sub : " " + sub));
                }
            }
        }
        return curr;
    }
};