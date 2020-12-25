class Solution {
public:
    string minWindow(string s, string t) {
        int left = -1, right = t.length(), start = 0;
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        int tRem = tCount.size();
        
        for (int i = 0; i < s.length(); i++) {
            if (tCount.count(s[i])) {
                tCount[s[i]]--;
                if (tCount[s[i]] == 0) {
                    tRem--;
                }                            
                while (tRem == 0) {                    
                    if (left < 0 || i - start <= right - left) {
                        left = start;
                        right = i;
                    }
                    if (tCount.count(s[start])) {
                        tCount[s[start]]++;
                        if (tCount[s[start]] > 0) {
                            tRem++;
                        }                        
                    }    
                    start++;
                }
            }
        }
        return left < 0 ? "" : s.substr(left, right - left + 1);
    }
};