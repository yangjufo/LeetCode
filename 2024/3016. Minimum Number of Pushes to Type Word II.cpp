class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> counts;
        for (char c : word) {
            counts[c]++;
        }
        vector<pair<int, char>> ps;
        for (auto& [c, i] : counts) {
            ps.push_back({i, c});
        }
        sort(ps.begin(), ps.end());
        int total = 0;
        for (int i = ps.size() - 1; i >= 0; i--) {
            total += ps[i].first * ((ps.size() - i + 7) / 8);
        }
        return total;
    }
};