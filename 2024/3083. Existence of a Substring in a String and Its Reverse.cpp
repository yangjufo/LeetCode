class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> ss;
        for (int i = 0; i < s.length() - 1; i++) {
            ss.insert(s.substr(i, 2));
        }
        string sc = s;
        reverse(sc.begin(), sc.end());
        for (int i = 0; i < s.length() - 1; i++) {
            if (ss.find(sc.substr(i, 2)) != ss.end()) {
                return true;
            }
        }
        return false;
    }
};