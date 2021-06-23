class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<unordered_set<int>> edgeMap(n);
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].insert(edge[1]);
        }
        vector<bool> visited(n, false), path(n, false);
        return dfs(edgeMap, visited, path, source, destination);
    }
    
    bool dfs(vector<unordered_set<int>>& edgeMap, vector<bool>& visited, vector<bool>& path, int source, int destination) {
        if (path[source]) return false;
        if (visited[source]) return true;
        visited[source] = true;        
        if (edgeMap[source].empty()) {
            return source == destination;
        }
        path[source] = true;
        for (int next : edgeMap[source]) {
            if (!dfs(edgeMap, visited, path, next, destination)) {
                return false;
            }
        }
        path[source] = false;
        return true;
    }
};