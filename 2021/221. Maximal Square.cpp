class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        int left[n], right[n], height[n];        
        for (int i = 0; i < n; i++) {
            left[i] = height[i] = 0;
            right[i] = n;
        }
        
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            int currLeft = 0, currRight = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], currLeft);
                    height[j] += 1;
                } else {
                    currLeft = j + 1;              
                    left[j] = 0;
                    height[j] = 0;
                }                                                                
            }            
            
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currRight);                    
                } else {
                    currRight = j;
                    right[j] = n;
                }
            }
            
            for (int j = 0; j < n; j++) {
                int minSide = min(right[j] - left[j], height[j]);
                maxArea = max(maxArea, minSide * minSide);
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        int maxLen = 0;        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    maxLen = max(dp[i][j], maxLen);
                }
            }
        }
        
        return maxLen * maxLen;
    }
};