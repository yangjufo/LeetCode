class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        vector<bool> bold(s.length(), false);
        for (int i = 0, end = 0; i < s.length(); i++) {
            for (string& w : words) {
                if (s.find(w, i) == i) {
                    end = max(end, i + (int)w.length());
                }
            }
            bold[i] = end > i;   
        }
        
        string res;
        int i = 0;
        while (i < s.length()) {
            if (!bold[i]) {
                res += s[i];
                i++;
                continue;
            }
            int start = i;
            while (i < s.length() && bold[i]) i++;
            res += "<b>" + s.substr(start, i - start) + "</b>";
        }
        return res;
    }
};