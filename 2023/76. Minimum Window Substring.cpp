class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.length(), start = 0, cand = 0, len = INT_MAX;
        unordered_map<char, int> tcount;
        for (int i = 0; i < t.length(); i++) {
            tcount[t[i]] += 1;
        }
        for (int i = 0; i < s.length(); i++) {
            tcount[s[i]] -= 1;
            if (tcount[s[i]] >= 0) {
                count -= 1;
            }
            while (count == 0) {
                if (i - start + 1 < len) {
                    cand = start;
                    len = i - start + 1;
                }
                tcount[s[start]] += 1;
                if (tcount[s[start]] >= 1) {
                    count += 1;
                }
                start += 1;
            }
        }
        return s.substr(cand, len == INT_MAX ? 0 : len);
    }
};