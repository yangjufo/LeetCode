class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int totalCost = 0;
        vector<bool> built(n + 1, false);
        unordered_map<int, unordered_map<int,int>> pipeMap;
        for (vector<int>& p : pipes) {
            if (pipeMap.find(p[1]) != pipeMap.end() && pipeMap[p[1]].find(p[0]) != pipeMap[p[1]].end()) {
                pipeMap[p[0]][p[1]] = pipeMap[p[1]][p[0]] = min(pipeMap[p[1]][p[0]], p[2]);
            } else {
                pipeMap[p[0]][p[1]] = pipeMap[p[1]][p[0]] = p[2];
            }
        }
        auto comparator = [](pair<int, int>& left, pair<int ,int>& right) {
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comparator)> costQueue(comparator);
        for (int i = 0; i < wells.size(); i++) {
            costQueue.push({i + 1, wells[i]});
        }
        while (!costQueue.empty()) {
            auto curr = costQueue.top();
            costQueue.pop();
            if (built[curr.first]) continue;
            built[curr.first] = true;
            totalCost += curr.second;
            for (auto& iter : pipeMap[curr.first]) {
                if (built[iter.first]) continue;
                costQueue.push({iter.first, iter.second});
            }
        }
        return totalCost;
    }
};