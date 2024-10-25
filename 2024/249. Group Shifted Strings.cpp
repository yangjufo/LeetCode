class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        for (string& s : strings) {
            string key;
            for (int i = 1; i < s.length(); i++) {
                key += to_string((s[i] + 'z' - s[i - 1]) % 26) + "#";
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : map) {
            res.push_back(v);
        }
        return res;
    }
};