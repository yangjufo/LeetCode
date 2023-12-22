class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0);
        for (vector<int>& edge : edges) {
            degrees[edge[0]] += 1;
            degrees[edge[1]] += 1;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> queue;
        for (int i = 0; i < degrees.size(); i++) {
           if (degrees[i] == 1) {
                degrees[i] -= 1;
                queue.push(i);
            }
        }
        vector<int> res;
        while (!queue.empty() && n > 2) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int curr = queue.front();
                queue.pop();
                n -= 1;
                for (int next : graph[curr]) {
                    degrees[next] -= 1;
                    if (degrees[next] == 1) {
                        queue.push(next);
                    }
                }
            }
        }
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            res.push_back(curr);
        }
        return res;
    }
};