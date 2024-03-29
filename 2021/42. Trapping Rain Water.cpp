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

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int) height.size() - 1, water = 0;
        int maxLeft = 0, maxRight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    water += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxRight) {
                    water += maxRight - height[right];
                } else {
                    maxRight = height[right];
                }
                right--;
            }
        }
        return water;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int) height.size() - 1, total = 0, maxLeft = INT_MIN, maxRight = INT_MIN;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    total += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxRight) {
                    total += maxRight - height[right];
                } else {
                    maxRight = height[right];
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
        int left = 0, right = (int) height.size() - 1, total = 0, maxLeft = INT_MIN, maxRight = INT_MIN;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    total += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxRight) {
                    total += maxRight - height[right];
                } else {
                    maxRight = height[right];
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
        int sum = 0, left = 0, right = (int)height.size() - 1, maxLeft = 0, maxRight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    sum += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    sum += maxRight - height[right];
                }
                right--;
            }
        }
        return sum;
    }
};