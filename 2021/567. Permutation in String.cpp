class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);
        for (char c : s1) {
            count1[c - 'a']++;
        }
        int start = 0;
        for (int i = 0; i < s2.length(); i++) {
            count2[s2[i] - 'a']++;
            while (count2[s2[i] - 'a'] > count1[s2[i] - 'a']) {
                count2[s2[start] - 'a']--;
                start++;                
            }
            if (i - start + 1 == s1.length()) {
                return true;
            }
        }
        return false;
    }
};