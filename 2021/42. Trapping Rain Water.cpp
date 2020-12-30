class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    res += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxRight) {
                    res += maxRight - height[right];
                } else {
                    maxRight = height[right];                    
                }
                right--;
            }            
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {        
        int maxLeft[height.size()], maxRight[height.size()];        
        for (int i = 0; i < height.size(); i++) {            
            maxLeft[i] = (i == 0) ? height[i] : max(height[i], maxLeft[i - 1]);
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            maxRight[i] = (i == height.size() - 1) ? height[i] : max(height[i], maxRight[i + 1]);
        }
        
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return res;
    }
};