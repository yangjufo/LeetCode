class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> counts = {{'#', 0}};
        for (char c : s) {
            if (counts.back().first != c) {
                counts.push_back({c, 1});
            } else {
                counts.back().second++;
                if (counts.back().second == k) {
                    counts.pop_back();
                }
            }
        }
        string res;
        for (auto& p : counts) {
            res += string(p.second, p.first);
        }
        return res;
    }
};