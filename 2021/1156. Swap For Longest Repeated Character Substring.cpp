class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> count(26, 0);
        for (char c : text) {
            count[c - 'a']++;
        }
        int maxLen = 0;
        for (int i = 0; i < 26; i++) {
            char target = i + 'a';
            int targetCount = 0, notCount = 0, start = 0;
            for (int j = 0; j < text.size(); j++) {
                if (text[j] == target) {
                    targetCount++;
                } else {
                    notCount++;
                }
                while (notCount > 1 || (notCount == 1 && count[i] < targetCount + 1)) {
                    if (text[start] == target) {
                        targetCount--;
                    } else {
                        notCount--;
                    }
                    start++;
                }
                maxLen = max(maxLen, j - start + 1);
            }            
        }
        return maxLen;
    }
};

class Solution {
public:    
    int maxRepOpt1(string text) {
        vector<vector<int>> indexes(26);
        for (int i = 0; i < text.length(); i++) {
            indexes[text[i] - 'a'].push_back(i);
        }
        
        int res = 0;
        for (int i = 0; i < 26; i++) {
            int count = 1, prevCount = 0, maxLen = 0;
            for (int j = 1; j < indexes[i].size(); j++) {
                if (indexes[i][j] == indexes[i][j - 1]  + 1) {
                    count++;
                } else {
                    prevCount = (indexes[i][j - 1] + 2 == indexes[i][j]) ? count : 0;
                    count = 1;
                }                
                maxLen = max(maxLen, prevCount + count + (prevCount + count < indexes[i].size() ? 1 : 0));
            }
            res = max(res, maxLen == 0 ? 1 : maxLen);
        }
        return res;
    }
};