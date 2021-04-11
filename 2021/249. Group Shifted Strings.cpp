class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> diffMap;
        for (string str : strings) {                        
            string diff = "#";
            for (int i = 1; i < str.length(); i++) {
                diff += to_string((str[i] + 26 - str[i - 1]) % 26) + "#";
            }
            diffMap[diff].push_back(str);
        }
        vector<vector<string>> res;
        for (auto & iter : diffMap) {
            res.push_back(iter.second);
        }
        return res;
    }
};