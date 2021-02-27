class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {       
        stack<int> stack;
        int start = nums.size(), end = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[stack.top()] > nums[i]) {
                start = min(start, stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) stack.pop();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stack.empty() && nums[stack.top()] < nums[i]) {
                end = max(end, stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        return end > start ? end - start + 1 : 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = -1, maxVal = INT_MIN, minVal = INT_MAX;
        int i = 0, j = nums.size() - 1;
        while (j >= 0) {
            if (nums[i] >= maxVal) {
                maxVal = nums[i];
            } else {
                end = i;
            }
            
            if (nums[j] <= minVal) {
                minVal = nums[j];
            } else {
                start = j;
            }
            
            i++;
            j--;
        }
        
        return end - start + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN, start = 0, end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= maxVal) {
                maxVal = nums[i];
            } else {
                end = i;
            }
        }        
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= minVal) {
                minVal = nums[i];
            } else {
                start = i;
            }
        }
        
        return end - start + 1;
    }    
};