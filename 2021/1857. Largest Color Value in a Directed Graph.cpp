class Solution {
public:
    bool cycle = false;
    int maxCount = 0, N;        
    vector<bool> visited;
    vector<vector<int>> mem;
    unordered_map<int, vector<int>> edgeMap;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        N = colors.length();    
        visited.resize(N, false);
        mem.resize(N, vector<int>(0));
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < N; i++) {       
            dfs(edgeMap, colors, i);
            if (cycle) return -1;
            for (int c : mem[i]) {
                maxCount = max(c, maxCount);
            }
        }
        return maxCount;
    }
    
    void dfs(unordered_map<int, vector<int>>& edgeMap, string& colors, int start) {        
        if (visited[start]) {
            cycle = true;
            return;
        }
        if (!mem[start].empty()) return;
        visited[start] = true;
        mem[start].resize(26, 0);        
        for (int next : edgeMap[start]) {
            dfs(edgeMap, colors, next);
            if (cycle) return;
            for (int i = 0; i < 26; i++) {       
                mem[start][i] = max(mem[start][i], mem[next][i]);
            }            
        }
        mem[start][colors[start] - 'a']++;
        visited[start] = false;
    }
    
};