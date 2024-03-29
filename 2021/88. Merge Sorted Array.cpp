class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0 || (j >= 0 && nums1[i] < nums2[j])) {
                nums1[index] = nums2[j];
                j--;
            } else {
                nums1[index] = nums1[i];
                i--;
            }
            index--;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[i + j + 1] = nums1[i];
                i--;
            } else {
                nums1[i + j + 1] = nums2[j];
                j--;
            }
        }
        while (j >= 0) {
            nums1[i + j + 1] = nums2[j];
            j--;
        }        
    }
};