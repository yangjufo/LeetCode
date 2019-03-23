class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        if (s.length() == 0)
            return true;
        int count_s[26], count_t[26];
        for (int i = 0; i < 26; i++){
            count_s[i] = 0;
            count_t[i] = 0;
        }
        for (int i = 0; i < s.length(); i++){
            count_s[s[i] - 97] += 1;
        }
        for (int i = 0; i < t.length(); i++){
            count_t[t[i] - 97] += 1;
        }
        for (int i = 0; i < 26; i++){
            if (count_s[i] != count_t[i])
                return false;
        }
        return true;
    }
};