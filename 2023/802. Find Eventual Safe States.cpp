class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rg(graph.size());
        vector<int> degrees(graph.size(), 0);
        queue<int> queue;
        for (int i = 0; i < graph.size(); i++) {
            degrees[i] = graph[i].size();
            if (degrees[i] == 0) {
                queue.push(i);
            }
            for (int j : graph[i]) {
                rg[j].push_back(i);
            }
        }
        vector<int> res;
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            res.push_back(curr);
            for (int prev : rg[curr]) {
                degrees[prev] -= 1;
                if (degrees[prev] == 0) {
                    queue.push(prev);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};