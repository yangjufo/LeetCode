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

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCount, sCount;
        for (char c : t) {
            tCount[c - 'a']++;
        }
        int start = 0, minLen = s.length() + 1, found = 0, minStart = 0;
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            if (sCount[s[i] - 'a'] <= tCount[s[i] - 'a']) {
                found++;
            }
            while (found >= t.length()) {
                if (i - start + 1 < minLen) {
                    minLen = i - start + 1;
                    minStart = start;
                }
                sCount[s[start] - 'a']--;
                if (sCount[s[start] - 'a'] < tCount[s[start] - 'a']) {
                    found--;
                }                
                start++;
            }            
        }
        return minLen > s.length() ? "" : s.substr(minStart, minLen);
    }
};