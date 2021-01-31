class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> edges;
        for (vector<int>& a : adjacentPairs) {
            edges[a[0]].push_back(a[1]);
            edges[a[1]].push_back(a[0]);           
        }
        int start = 0;
        for (auto& edge : edges) {
            if (edge.second.size() < 2) {
                start = edge.first;
                break;
            }
        }
        unordered_set<int> visited;
        dfs(edges, start, ans, visited);
        return ans;
        
    }
    void dfs(unordered_map<int, vector<int>>& edges, int start, vector<int>& ans, unordered_set<int>& visited) {        
        ans.push_back(start);
        visited.insert(start);
        for (int next : edges[start]) {
            if (visited.find(next) == visited.end()) {                
                dfs(edges, next, ans, visited);
                break;
            }
        }
    }
};

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> edges;
        for (vector<int>& a : adjacentPairs) {
            edges[a[0]].push_back(a[1]);
            edges[a[1]].push_back(a[0]);           
        }
        for (auto& edge : edges) {
            if (edge.second.size() < 2) {
                ans.push_back(edge.first);
                ans.push_back(edge.second[0]);
                break;
            }
        }
        
        while (ans.size() < edges.size()) {
            if (edges[ans.back()][0] != ans[ans.size() - 2]) {
                ans.push_back(edges[ans.back()][0]);
            } else {
                ans.push_back(edges[ans.back()][1]);
            }
        }
        
        return ans;
        
    }
};