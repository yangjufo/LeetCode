class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1;
        for (int n : nums1) {
            count1[n] += 1;
        }
        vector<int> res;
        for (int n : nums2) {
            if (count1[n] > 0) {
                count1[n] -= 1;
                res.push_back(n);
            }
        }
        return res;

    }
};