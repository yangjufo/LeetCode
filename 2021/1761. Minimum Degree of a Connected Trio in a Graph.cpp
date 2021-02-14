class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> edgeMap(n + 1, vector<bool>(n + 1, false));        
        vector<int> degrees(n + 1, 0);
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]][edge[1]] = true;
            edgeMap[edge[1]][edge[0]] = true;
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        
        int minDegrees = -1;
        for (int i = 1; i <= n; i++) {            
            for (int j = i + 1; j <= n; j++) {
                if (edgeMap[i][j]) {
                    for (int k = j + 1; k <= n; k++) {                    
                        if (edgeMap[i][k] && edgeMap[j][k]) {       
                            int currDegrees = degrees[i] + degrees[j] + degrees[k] - 6;
                            if (minDegrees == -1 || currDegrees < minDegrees) {
                                minDegrees = currDegrees;
                            }
                        }
                    }
                }
            }
        }
        
        return minDegrees;
    }
};