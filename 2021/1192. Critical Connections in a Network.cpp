class Solution {
public:
        
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        unordered_map<int, int> ranks;
        unordered_set<string> connectSet;
                
        for (vector<int>& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
            connectSet.insert(to_string(min(conn[0], conn[1])) + "#" + to_string(max(conn[0], conn[1])));
        }
        for (int i = 0; i < n; i++) {
            ranks[i] = -2;
        }
        
        dfs(0, 0, graph, ranks, connectSet);
        
        vector<vector<int>> res;
        for (auto& conn : connectSet) {
            int splitIndex = conn.find("#");
            res.push_back({stoi(conn.substr(0, splitIndex)), stoi(conn.substr(splitIndex + 1))});
        }
        return res;        
    }
    
    int dfs(int node, int rank, vector<vector<int>>& graph, unordered_map<int, int>& ranks, unordered_set<string>& connectSet) {
        if (ranks[node] != -2) {
            return ranks[node];
        }
        
        ranks[node] = rank;
        int minRank = rank + 1;
        for (int neigh : graph[node]) {
            int neighRank = ranks[neigh];
            if (neighRank != -2 && neighRank == rank - 1) {
                continue;
            }
            
            neighRank = dfs(neigh, rank + 1, graph, ranks, connectSet);
            if (neighRank <= rank) {
                connectSet.erase(to_string(min(node, neigh)) + "#" + to_string(max(node, neigh)));
            }
            
            minRank = min(minRank, neighRank);
        }
        return minRank;
    }
};

class Solution {
public:
        
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        unordered_map<int, int> ranks;
        vector<vector<int>> res;
                
        for (vector<int>& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        for (int i = 0; i < n; i++) {
            ranks[i] = -2;
        }
        
        dfs(0, 0, n, graph, ranks, res);
                
        return res;        
    }
    
    int dfs(int node, int rank, int n, vector<vector<int>>& graph, unordered_map<int, int>& ranks, vector<vector<int>>& res) {
        if (ranks[node] != -2) {
            return ranks[node];
        }
        
        ranks[node] = rank;
        int minRank = rank;
        for (int neigh : graph[node]) {
            int neighRank = ranks[neigh];
            if (neighRank == n || neighRank == rank - 1) {
                continue;
            }
            
            neighRank = dfs(neigh, rank + 1, n, graph, ranks, res);
            if (neighRank > rank) {
                res.push_back({node, neigh});
            }
            
            minRank = min(minRank, neighRank);
        }     
        ranks[node] = n;
        return minRank;
    }
};