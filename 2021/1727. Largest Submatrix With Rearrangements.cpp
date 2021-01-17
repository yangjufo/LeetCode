class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();               
        int maxArea = 0;
        vector<int> height(n, 0); 
        for (int i = 0; i < m; i++) {            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    height[j]++;                    
                } else {
                    height[j] = 0;
                }
            }            
            vector<int> tmp(height.begin(), height.end());
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, tmp[j] * (j + 1));
            }
        }        
        return maxArea;
    }
};