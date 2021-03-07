class Solution {
public:
    int mod = 1000'000'007;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> edgeMap;
        vector<int> shortest(n + 1, INT_MAX);
        shortest[n] = 0;
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]][edge[1]] = edge[2];
            edgeMap[edge[1]][edge[0]] = edge[2];
        }                                
        
        auto comparator = [](pair<int, int>& left, pair<int, int>& right) {
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> nodeQueue(comparator);        
        nodeQueue.push({n, 0});
        while (!nodeQueue.empty()) {
            int node = nodeQueue.top().first;
            int dis = nodeQueue.top().second;
            nodeQueue.pop();            
            if (dis != shortest[node]) continue;            
            vector<pair<int, int>> neighbors;
            for (auto& iter : edgeMap[node]) {
                if (shortest[node] + iter.second < shortest[iter.first]) {
                    shortest[iter.first] = shortest[node] + iter.second;
                    nodeQueue.push({iter.first, shortest[iter.first]});
                }                
            }
        }
        
        vector<int> mem(n + 1, 0); 
        dfs(edgeMap, 1, mem, shortest, n);        
        
        return mem[1];
    }
    
    int dfs(unordered_map<int, unordered_map<int, int>>& edgeMap, int node, vector<int>& mem, vector<int>& shortest, int n) {        
        if (node == n) {          
            return 1;
        }
        if (mem[node] > 0) return mem[node];        
        for (auto& iter : edgeMap[node]) {
            if (shortest[iter.first] < shortest[node]) {
                mem[node] = (mem[node] + dfs(edgeMap, iter.first, mem, shortest, n)) % mod;
            }
        }
        return mem[node];
    }
};