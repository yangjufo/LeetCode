class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> leftMin;
        int currMin = INT_MAX;
        for (int n : nums) {
            leftMin.push_back(currMin);
            currMin = min(currMin, n);
        }
        stack<int> rightClose;
        int closeMin = INT_MIN;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {            
            while (!rightClose.empty() && nums[i] > rightClose.top()) {
                closeMin = rightClose.top();
                rightClose.pop();
            }
            rightClose.push(nums[i]);
            if (leftMin[i] < closeMin) {
                return true;
            }
        }
        return false;        
    }
};