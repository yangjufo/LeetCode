class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> edgeMap(n, vector<int>{});
        
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;    
        dfs(edgeMap, 0, visited);
        
        return visited.size() == n;
    }
    
    void dfs(vector<vector<int>>& edgeMap, int start, unordered_set<int>& visited) { 
        if (visited.count(start)) return;
        visited.insert(start);   
        for (int neigh : edgeMap[start]) {
            dfs(edgeMap, neigh, visited);            
        }                
    }
};