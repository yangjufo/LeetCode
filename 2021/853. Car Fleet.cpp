class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, int>> arrivals;
        for (int i = 0; i < position.size(); i++) {            
            arrivals.push_back({(target - position[i]) * 1.0 / speed[i], position[i]});
        }
        sort(arrivals.begin(), arrivals.end(), [](auto& left, auto& right) {
            return left.first == right.first ? left.second > right.second : left.first > right.first;
        });
        int count = 0, currMax = -1;
        for (auto a : arrivals) {
            if (a.second > currMax) {
                count++;
                currMax = a.second;
            }
        }
        return count;
    }
};