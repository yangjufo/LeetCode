class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {                
                res.push_back(nums1[i]);                
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1, count2;
        for (int n : nums1) {
            count1[n]++;
        }
        for (int n : nums2) {
            count2[n]++;
        }
        vector<int> res;
        for (auto& iter : count1) {
            if (count2.find(iter.first) != count2.end()) {
                for (int i = 0; i < min(iter.second, count2[iter.first]); i++) {
                    res.push_back(iter.first);
                }
            }
        }
        return res;
    }
};