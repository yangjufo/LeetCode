class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> hStack;
        hStack.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (hStack.top() != -1 && heights[i] <= heights[hStack.top()]) {
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