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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {        
        unordered_map<int, int> nums1Map;
        for (int i = 0; i < nums1.size(); i++) {
            nums1Map[nums1[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        stack<int> nums2Stack;
        for (int n : nums2) {
            while (!nums2Stack.empty() && n > nums2Stack.top()) {
                if (nums1Map.find(nums2Stack.top()) != nums1Map.end()) {
                    res[nums1Map[nums2Stack.top()]] = n;                    
                }
                nums2Stack.pop();
            }
            nums2Stack.push(n);
        }
        return res;
    }
};