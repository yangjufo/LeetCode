class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> sIndex;
        for (int i = 0; i < score.size(); i++) {
            sIndex.push_back({score[i], i});
        }
        sort(sIndex.begin(), sIndex.end(), [](pair<int,int>& left, pair<int, int>& right) {
            return left.first > right.first;
        });
        vector<string> res(score.size(), "");
        for (int i = 0; i < sIndex.size(); i++) {
            if (i == 0) {
                res[sIndex[i].second] = "Gold Medal";
            } else if (i == 1) {
                res[sIndex[i].second] = "Silver Medal";
            } else if (i == 2) {
                res[sIndex[i].second] = "Bronze Medal";
            } else {
                res[sIndex[i].second] = to_string(i + 1);
            }
        }
        return res;
    }
};