class Solution {
public:
    vector<int> count, ans;
    vector<unordered_set<int>> graph;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        count.resize(N, 1);
        ans.resize(N, 0);
        graph.resize(N, {});
        for (vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1, N);
        return ans;
    }
    
    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    void dfs2(int node, int parent, int N) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node, N);
            }
        }
    }
    
};