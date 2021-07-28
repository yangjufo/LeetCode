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

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> line = triangle[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                line[j] = min(line[j], line[j + 1]) + triangle[i][j];
            }
        }
        return line[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> sums;
        for (int i = 0; i < triangle.size(); i++) {
            sums.push_back((i == 0 ? 0 : sums.back()) + triangle[i].back());
            for (int j = (int)sums.size() - 2; j >= 0; j--) {
                sums[j] = min(sums[j], (j == 0 ? INT_MAX : sums[j - 1])) + triangle[i][j];
            }
        }
        int minSum = INT_MAX;
        for (int s : sums) {
            minSum = min(minSum, s);
        }
        return minSum;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> sums = triangle[n - 1];        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)            
                sums[j] = min(sums[j + 1], sums[j]) + triangle[i][j];            
        }
        return sums[0];
    }
};