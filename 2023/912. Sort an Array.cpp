class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }

    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return {nums[left]};
        }
        int mid = left + (right - left) / 2;
        vector<int> leftNum = mergeSort(nums, left, mid);
        vector<int> rightNum = mergeSort(nums, mid + 1, right);
        return merge(leftNum, rightNum);
    }

    vector<int> merge(vector<int>& left, vector<int>& right) {
        int l = 0, r = 0;
        vector<int> ret;
        while (l < left.size() || r < right.size()) {
            if (l >= left.size() || (r < right.size() && left[l] > right[r])) {
                ret.push_back(right[r]);
                r++;
            } else {
                ret.push_back(left[l]);
                l++;
            }
        }
        return ret;
    }
};