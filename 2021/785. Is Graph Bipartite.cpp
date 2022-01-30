class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (color[i] > -1) continue;
            queue<int> nodeQueue;
            nodeQueue.push(i);
            color[i] = 1;
            while (!nodeQueue.empty()) {
                int curr = nodeQueue.front();
                nodeQueue.pop();
                for (int neigh : graph[curr]) {
                    if (color[neigh] == -1) {
                        color[neigh] = 1 - color[curr];
                        nodeQueue.push(neigh);
                    } else if (color[neigh] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};


class Solution {
public:
    vector<int> colors;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.resize(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] != -1) continue;
            if (!dfs(graph, 0, i)) return false;
        }                
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int color, int node) {
        if (colors[node] != -1) {
            return colors[node] == color;
        }
        colors[node] = color;
        for (int neigh : graph[node]) {
            if (!dfs(graph, 1 - color, neigh)) {
                return false;
            }
        }
        return true;
    }
};
