class Solution {
public:
    int maxArea(vector<int>& height) {        
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            int tmpArea = min(height[left], height[right]) * (right - left);
            ans = max(tmpArea, ans);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                res = max(res, height[left] * (right - left));
                left++;
            } else {
                res = max(res, height[right] * (right - left));
                right--;
            }
        }
        return res;
    }
};