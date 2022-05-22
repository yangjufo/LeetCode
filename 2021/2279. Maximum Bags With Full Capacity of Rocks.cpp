class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int, int>> curr;
        for (int i = 0; i < capacity.size(); i++) {
            curr.push_back({capacity[i], rocks[i]});
        }
        sort(curr.begin(), curr.end(), [](pair<int, int>& l, pair<int, int>& r) {
           return l.first - l.second < r.first - r.second;
        });
        int count = 0, index = 0;
        while (additionalRocks > 0 && index < curr.size()) {
            if (additionalRocks >= curr[index].first - curr[index].second) {
                count++;
            }
            additionalRocks -= curr[index].first - curr[index].second;
            index++;
        }
        return count;
    }
};