class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, unordered_map<int, double>> probMap;
        for (int i = 0; i < edges.size(); i++) {
            probMap[edges[i][0]][edges[i][1]] = succProb[i];
            probMap[edges[i][1]][edges[i][0]] = succProb[i];
        }
        vector<double> nodeProbs(n, INT_MIN);
        auto Compare = [](pair<int, double>& l, pair<int, double>& r) {
            return l.second < r.second;
        };
        priority_queue<pair<int, double>, vector<pair<int, double>>,
                       decltype(Compare)>
            maxProb(Compare);
        int res = 0;
        for (const auto& [node, prob] : probMap[start_node]) {
            maxProb.push({node, prob});
        }
        while (!maxProb.empty()) {
            int node = maxProb.top().first;
            double prob = maxProb.top().second;
            maxProb.pop();
            if (prob > nodeProbs[node]) {
                for (const auto& [next, np] : probMap[node]) {
                    maxProb.push({next, prob * np});
                }
                nodeProbs[node] = prob;
            }
        }
        return nodeProbs[end_node] < 0 ? 0 : nodeProbs[end_node];
    }
};