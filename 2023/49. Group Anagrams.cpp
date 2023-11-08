class Solution {
public:
    vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k, sv] : ans) {
            res.push_back(sv);
        }
        return res;
    }
};