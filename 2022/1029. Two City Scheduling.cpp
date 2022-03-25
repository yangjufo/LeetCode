class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& l, auto& r) {
            return abs(l[0] - l[1]) > abs(r[0] - r[1]);
        });
        int a = costs.size() / 2, b = costs.size() / 2, total = 0;
        for (const auto& c : costs) {
            if ((a > 0 && c[0] < c[1]) || b == 0) {
                a--;
                total += c[0];
            } else {
                b--;
                total += c[1];
            }
        }
        return total;
    }
};