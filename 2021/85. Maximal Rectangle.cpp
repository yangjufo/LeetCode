class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            maxRect = max(maxRect, maxOneRow(heights));
        }
        return maxRect;
    }
    
    int maxOneRow(vector<int>& heights) {
        stack<int> hStack;
        hStack.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (hStack.top() != -1 && heights[i] < heights[hStack.top()]) {
                int height = heights[hStack.top()];
                hStack.pop();
                maxArea = max(maxArea, height * (i - hStack.top() - 1));
            }
            hStack.push(i);
        }
        while (hStack.top() != -1) {
            int height = heights[hStack.top()];
            hStack.pop();
            int tmpArea = height * (heights.size() - hStack.top() - 1);
            maxArea = max(maxArea, tmpArea);
        }
        return maxArea;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        
        int maxRect = 0;
        for (int i = 0; i < m; i++) {
            int curLeft = 0, curRight = n;
            for (int j = 0; j < n; j++) {       
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], curLeft);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n;
                    curRight = j;
                }                
            }
            
            for (int j = 0; j < n; j++) {
                maxRect = max(maxRect, (right[j] - left[j]) * height[j]);
            }
        }
        return maxRect;
    }
};


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int M = matrix.size();
        if (M == 0) return 0;
        int N = matrix[0].size(), maxArea = 0;
        vector<int> left(N, 0), right(N, N), height(N, 0);
        for (int i = 0; i < M; i++) {
            int currLeft = 0, currRight = N;
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;                    
                    left[j] = max(currLeft, left[j]);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }
            for (int j = N - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {                    
                    right[j] = min(currRight, right[j]);
                } else {
                    currRight = j;
                    right[j] = N;
                }
            }
            for (int j = 0; j < N; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }            
        }
        return maxArea;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? m : matrix[0].size();        
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {            
            int currLeft = 0, currRight = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                    left[j] = max(left[j], currLeft);
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
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};