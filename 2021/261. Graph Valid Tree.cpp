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

class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    int total;
    bool validTree(int n, vector<vector<int>>& edges) { 
        if (edges.size() != n - 1) return false;        
        total = n;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(1);
        }
        
        for (vector<int>& edge : edges) {
            merge(edge[0], edge[1]);
        }
        
        return total <= 1;
    }
    
    int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        return parents[node];
    }
    
    void merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX != pY) {
            total--;
            if (ranks[pX] > ranks[pY]) {
                parents[pY] = pX;
            } else {
                parents[pX] = pY;
                if (ranks[pX] == ranks[pY]) {
                    ranks[pY]++;
                }
            }            
        }
    }
    
    
};

class Solution {
public:
    vector<int> parents, ranks;    
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }        
        for (vector<int>& edge : edges) {
            if (merge(edge[0], edge[1])) {
                n--;
            }
        }        
        return n == 1;
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);            
        }
        return parents[x];
    }
    
    bool merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX == pY) {
            return false;
        }
        if (ranks[pX] > ranks[pY]) {
            parents[pY] = pX;
        } else {
            parents[pX] = pY;
            if (ranks[pX] = ranks[pY]) {
                ranks[pY]++;
            }
        }
        return true;
    }
    
};