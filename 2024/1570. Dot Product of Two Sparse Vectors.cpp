class SparseVector {
public:
    unordered_map<int, int> numMap;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                numMap[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (const auto [index, value] : vec.numMap) {
            res += value * numMap[index];
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);