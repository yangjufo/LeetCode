class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height.back();
        int total = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    total += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    total += rightMax - height[right];
                }
                right--;
            }
        }
        return total;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int leftIndex = 0, rightIndex = height.size() - 1, leftMost = 0,
            rightMost = 0, total = 0;
        while (leftIndex < rightIndex) {
            if (height[leftIndex] < height[rightIndex]) {
                leftMost = max(leftMost, height[leftIndex]);
                total += leftMost - height[leftIndex];
                leftIndex += 1;
            } else {
                rightMost = max(rightMost, height[rightIndex]);
                total += rightMost - height[rightIndex];
                rightIndex -= 1;
            }
        }
        return total;
    }
};