class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> nStack;
        vector<int> res(nums.size(), -1);
        int n = nums.size();
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!nStack.empty() && nums[i % n] > nStack.top().first) {
                if (res[nStack.top().second] == -1) {
                    res[nStack.top().second] = nums[i % n];
                }
                nStack.pop();
            }
            nStack.push({nums[i % n], i % n});
        }
        return res;
    }
};