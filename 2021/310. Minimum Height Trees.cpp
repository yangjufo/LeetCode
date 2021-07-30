class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {        
        if (n <= 1) {
            return { 0 };
        }
        vector<int> res, degrees(n, 0);
        vector<vector<int>> edgeMap(n);
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }        
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                res.push_back(i);
                degrees[i]--;
            }
        }
        int rem = n;
        while (rem > 2) {
            rem -= res.size();
            vector<int> tmp;
            for (int leaf : res) {                
                for (int nei : edgeMap[leaf]) {
                    degrees[nei]--;
                    if (degrees[nei] == 1) {
                        tmp.push_back(nei);
                    }
                }
            }
            res = tmp;
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1) return { 0 };
        
        vector<int> degrees(n, 0);
        vector<vector<int>> edgeMap(n);
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
                
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                res.push_back(i);
                degrees[i]--;            
            }
        }           
        
        int rem = n;
        while (rem > 2) {   
            rem -= res.size();
            vector<int> tmp;
            for (int node : res) {                                
                for (int neigh : edgeMap[node]) {
                    degrees[neigh]--;
                    if (degrees[neigh] == 1) {
                        tmp.push_back(neigh);                        
                    }
                }
            }
            res = tmp;
        }
        
        return res;
    }
};