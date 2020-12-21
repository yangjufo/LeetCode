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