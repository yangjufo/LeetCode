class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> wins, loses;
        for (vector<int>& m : matches) {
            wins[m[0]] += 1;
            loses[m[1]] += 1;
        }
        vector<vector<int>> res(2);
        for (auto& iter : wins) {
            if (loses.find(iter.first) == loses.end()) {
                res[0].push_back(iter.first);
            }
        }
        for (auto& iter : loses) {
            if (iter.second == 1) {
                res[1].push_back(iter.first);
            }
        }
        return res;
    }
};