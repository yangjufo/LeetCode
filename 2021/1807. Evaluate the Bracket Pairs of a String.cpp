class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv;
        for (auto& kn : knowledge) {
            kv[kn[0]] = kn[1];
        }
        string res, key;
        bool open = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open = true;
            } else if (s[i] == ')') {
                open = false;                
                if (kv.find(key) == kv.end()) {
                    res += "?";
                } else {
                    res += kv[key];
                }                
                key.clear();
            } else {
                if (open) {
                    key += s[i];
                } else {
                    res += s[i];
                }
            }
        }
        return res;
    }
};