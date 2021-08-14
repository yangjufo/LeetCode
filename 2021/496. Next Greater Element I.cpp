class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> greaterStack;
        unordered_map<int, int> greaterMap;
        for (int n : nums2) {
            while (!greaterStack.empty() && n > greaterStack.top()) {
                greaterMap[greaterStack.top()] = n;
                greaterStack.pop();
            }
            greaterStack.push(n);
        }
        vector<int> res;
        for (int n : nums1) {
            if (greaterMap.find(n) == greaterMap.end()) {
                res.push_back(-1);
            } else {
                res.push_back(greaterMap[n]);
            }
        }
        return res;
    }
};