class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        bool canBreak[s.length() + 1];
        for (int i = 1; i <= s.length(); i++) canBreak[i] = false;
        canBreak[0] = true;
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (canBreak[j] && wordSet.count(s.substr(j, i - j + 1))) {                    
                    canBreak[i + 1] = true;
                    break;
                }                
            }            
        }
        
        return canBreak[s.length()];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int N = s.length();
        bool dp[N + 1];
        fill(dp, dp + N + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {                
                if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end() && dp[j]) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }        
        return dp[N];
    }
};

class Solution {
public:
    unordered_map<string, bool> mem;
    bool wordBreak(string s, vector<string>& wordDict) {
        return backtrack(s, wordDict);
    }
    
    bool backtrack(string s, vector<string>& wordDict) {        
        if (mem.find(s) != mem.end()) {
            return mem[s];            
        }
        if (s.empty()) {
            return true;
        }
        mem[s] = false;
        for (string& word : wordDict) {
            if (s.find(word) == 0) {
                if (backtrack(s.substr(word.length()), wordDict)) {
                    mem[s] = true;
                    break;
                }
            }
        }
        return mem[s];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.length()];
    }
};