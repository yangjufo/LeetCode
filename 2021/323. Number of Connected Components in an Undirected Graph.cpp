class Solution {
public:       
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
        
        int parents[n];
        for (int i = 0; i < n; i++) parents[i] = i;
        for (vector<int>& edge : edges) {
            int parentEdge0 = find(parents, edge[0]);
            int parentEdge1 = find(parents, edge[1]);
            
            if (parentEdge0 != parentEdge1) {
                parents[parentEdge0] = parentEdge1;
                n--;
            }
        }
        return n;
    }
    
    int find(int parents[], int x) {
        return parents[x] == x ? x : find(parents, parents[x]);
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> edgeMap;
        for (vector<int>& e : edges) {
            edgeMap[e[0]].push_back(e[1]);
            edgeMap[e[1]].push_back(e[0]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, edgeMap, visited);
            }
        }
        return count;
    }
    
    void dfs(int node, unordered_map<int, vector<int>>& edgeMap, vector<bool>& visited) {        
        for (int n : edgeMap[node]) {
            if (!visited[n]) {
                visited[n] = true;
                dfs(n, edgeMap, visited);
            }
        }
    }
};