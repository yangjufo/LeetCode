class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return {nums[left]};
        int mid = left + (right - left) / 2;
        vector<int> leftNum = mergeSort(nums, left, mid);
        vector<int> rightNum = mergeSort(nums, mid + 1, right);
        return merge(leftNum, rightNum);
    }
    
    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < left.size() || j < right.size()) {
            if (j >= right.size() || (i < left.size() && left[i] < right[j])) {
                res.push_back(left[i]);
                i++;
            } else {
                res.push_back(right[j]);
                j++;
            }        
        }
        return res;
    }
};