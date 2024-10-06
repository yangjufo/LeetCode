class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> edges;
        unordered_set<int> removed;
        for (vector<int>& i : invocations) {
            edges[i[0]].push_back(i[1]);
        }
        removed.insert(k);
        dfs(edges, removed, k);
        vector<int> all;
        for (int i = 0; i <= n - 1; i++) {
            all.push_back(i);
        }
        vector<int> remaining;
        for (int i = 0; i <= n -1; i++) {
            if (removed.find(i) == removed.end()) {
                for (int neigh : edges[i]) {
                    if (removed.find(neigh) != removed.end()) {
                        return all;
                    }
                }
                remaining.push_back(i);
            }
        }
        return remaining;
    }

    void dfs(unordered_map<int, vector<int>>& edges, unordered_set<int>& removed, int node) {
        for (int neigh : edges[node]) {
            if (removed.find(neigh) != removed.end()) {
                continue;
            }
            removed.insert(neigh);
            dfs(edges, removed, neigh);
        }
    }

};