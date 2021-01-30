class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1){
                    for (int k = j + 1; k < grid[0].size(); k++) {
                        if (grid[i][k] == 1) {
                            for (int l = 0; l < i; l++) {
                                if (grid[l][j] == 1 && grid[l][k] == 1) {
                                    count++;
                                }
                            }
                        }
                    }                    
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = m > 0 ? grid[0].size() : 0;
        vector<vector<int>> onePairs(n, vector<int>(n, 0));
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = j + 1; k < n; k++) {
                        if (grid[i][k] == 1) {
                            count += onePairs[j][k];
                            onePairs[j][k]++;
                        }                        
                    } 
                }                
            }
        }
        return count;
    }
};