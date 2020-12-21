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