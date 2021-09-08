class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> countP(26, 0), countS(26, 0), res;
        for (char c : p) {
            countP[c - 'a']++;
        }        
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            countS[s[i] - 'a']++;
            while (start <= i && countS[s[i] - 'a'] > countP[s[i] - 'a']) {
                countS[s[start] - 'a']--;
                start++;
            }
            if (i - start + 1 == p.length()) {
                res.push_back(start);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> countP(26, 0);
        for (char c : p) {
            countP[c - 'a']++;
        }
                
        vector<int> countS(26, 0), res;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            countS[s[i] - 'a']++;
            while (countS[s[i] - 'a'] > countP[s[i] - 'a']) {
                countS[s[start] - 'a']--;
                start++;
            }
            if (i - start + 1 == p.length()) {
                res.push_back(start);
            }
        }
        return res;
    }
};