class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> edgeMap;
        for (vector<int>& e : edges) {
            edgeMap[e[0]].push_back(e[1]);
            edgeMap[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> queue;
        queue.push(source);
        visited[source] = true;
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            if (curr == destination) {
                return true;
            }
            for (int next : edgeMap[curr]) {
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                queue.push(next);
            }
        }
        return false;
    }
};