class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for (int n : set1) {
            if (set2.find(n) == set2.end()) {
                res[0].push_back(n);
            }
        }
        for (int n : set2) {
            if (set1.find(n) == set1.end()) {
                res[1].push_back(n);
            }
        }
        return res;
    }
};