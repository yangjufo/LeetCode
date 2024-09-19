class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comparator = [](array<int, 3>& left, array<int, 3>& right) {
            return left[0] + left[1] > right[0] + right[1];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comparator)> pq(comparator);
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while (k > 0 && !pq.empty()) {
            k--;
            auto curr = pq.top();
            pq.pop();
            res.push_back({curr[0], curr[1]});
            if (curr[2] + 1 == nums2.size()) {
                continue;
            }
            pq.push({curr[0], nums2[curr[2] + 1], curr[2] + 1});
        }
        return res;
    }
};