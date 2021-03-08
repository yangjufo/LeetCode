class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); i++) {
            dp.push_back(vector<int>(triangle[i].size(), 0));
            if (i == 0) {
                dp[0][0] = triangle[0][0];
                continue;
            }
            for (int j = 0; j < triangle[i].size(); j++) {
                int last;                
                if (j == 0) {
                    last = dp[i - 1][j];
                } else if (j + 1 == triangle[i].size()) {                    
                    last = dp[i - 1][j - 1];
                } else {
                    last = min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = triangle[i][j] + last;            
            }
        }
        int minSum = INT_MAX;
        for (int i = 0; i < dp.back().size(); i++) {
            minSum = min(minSum, dp.back()[i]);
        }
        return minSum;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n-2; layer >= 0; layer--) // For each layer
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
    }
};