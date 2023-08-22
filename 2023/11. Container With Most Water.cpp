class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = 0, i = 0, j = (int)height.size() - 1, res = 0;
        while (i < j) {
            if (height[i] > left) {
                left = height[i];
            }
            if (height[j] > right) {
                right = height[j];
            }
            res = max(res, min(left, right) * (j - i));
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};