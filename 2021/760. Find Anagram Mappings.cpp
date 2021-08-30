class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < nums2.size(); i++) {
            indexes[nums2[i]].push_back(i);
        }
        vector<int> res;
        for (int n : nums1) {
            res.push_back(indexes[n].back());
            indexes[n].pop_back();
        }
        return res;
    }
};