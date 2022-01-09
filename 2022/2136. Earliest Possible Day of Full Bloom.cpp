class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> gs;
        for (int i = 0; i < growTime.size(); i++) {
            gs.push_back({growTime[i], i});
        }
        sort(gs.begin(), gs.end(), [](pair<int, int>& left, pair<int, int>& right) {
           return left.first > right.first;
        });

        int time = 0, maxTime = 0;
        for (auto& g : gs) {
            time += plantTime[g.second];
            maxTime = max(maxTime, time + g.first);
        }
        return maxTime;
    }
};