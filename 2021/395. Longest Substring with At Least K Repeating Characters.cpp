class Solution {
public:
    int longestSubstring(string s, int k) {
        int counter[26];                
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {            
            fill(counter, counter + 26, 0);
            for (int j = i; j < s.length(); j++) {
                counter[s[j] - 'a']++;                                
                        
                int c = 0;
                while (c < 26) {
                    if (counter[c] > 0 && counter[c] < k) {
                        break;
                    }
                    c++;
                }
                if (c == 26) {
                    maxLen = max(j - i + 1, maxLen);
                }
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int counter[26];
        int uniqueCount = 0;
        fill(counter, counter + 26, 0);
        for (char c : s) {
            counter[c - 'a']++;
            if (counter[c - 'a'] == 1) { 
                uniqueCount++;
            }
        }
            
        int maxLen = 0;
        for (int currUnique = 1; currUnique <= uniqueCount; currUnique++) {
            fill(counter, counter + 26, 0);
            int start = 0, end = 0, index = 0, unique = 0, countAtLeastK = 0;
            
            while (end < s.size()) {
                if (unique <= currUnique) {
                    index = s[end] - 'a';
                    if (counter[index] == 0) unique++;
                    counter[index]++;
                    if (counter[index] == k) countAtLeastK++;
                    end++;
                } else {
                    index = s[start] - 'a';
                    if (counter[index] == k) countAtLeastK--;
                    counter[index]--;
                    if (counter[index] == 0) unique--;
                    start++;
                }           
                
                if (unique == currUnique && unique == countAtLeastK) {
                    maxLen = max(maxLen, end - start);
                }
            }                        
        }
        return maxLen;
    }
};


class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> count(26, 0);
        int uniqueCount = 0;
        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] == 1) {
                uniqueCount++;
            }
        }
        
        int maxLen = 0;
        for (int i = 1; i <= uniqueCount; i++) {
            fill(count.begin(), count.end(), 0);
            int start = 0, end = 0, currUnique = 0, atLeastK = 0;
            while (end < s.length()) {
                if (currUnique <= i) {
                    count[s[end] - 'a']++;
                    if (count[s[end] - 'a'] == 1) {
                        currUnique++;
                    }                
                    if (count[s[end] - 'a'] == k) {
                        atLeastK++;
                    }
                    end++;
                } else {                    
                    if (count[s[start] - 'a'] == k) {
                        atLeastK--;
                    }
                    count[s[start] - 'a']--;
                    if (count[s[start] - 'a'] == 0) {
                        currUnique--;
                    }                     
                    start++;
                }
                
                if (currUnique == i && atLeastK == i) {
                    maxLen = max(maxLen, end - start);
                }
            }            
        }
        return maxLen;
    }
};