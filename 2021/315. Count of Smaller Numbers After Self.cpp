class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> indices(n);  // record the index. we are going to sort this array
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        // sort indices with their corresponding values in nums, i.e., nums[indices[i]]
        mergeSort(indices, 0, n, result, nums);
        return result;
    }

    void mergeSort(vector<int>& indices, int left, int right, vector<int>& result,
                   vector<int>& nums) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }

    void merge(vector<int>& indices, int left, int right, int mid, vector<int>& result,
               vector<int>& nums) {
        // merge [left, mid) and [mid, right)
        int i = left;  // current index for the left array
        int j = mid;   // current index for the right array
        // use temp to temporarily store sorted array
        vector<int> temp;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                // j - mid numbers jump to the left side of indices[i]
                result[indices[i]] += j - mid;
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        // when one of the subarrays is empty
        while (i < mid) {
            // j - mid numbers jump to the left side of indices[i]
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        while (j < right) {
            temp.push_back(indices[j]);
            j++;
        }
        // restore from temp
        move(temp.begin(), temp.end(), indices.begin() + left);
    }
};