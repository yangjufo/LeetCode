class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        while (start < arr.size() && arr[start] < x) {
            start += 1;
        }
        if (start >= arr.size() || (start > 0 && x - arr[start - 1] <= arr[start] - x)) {
            start -= 1;
        }
        int left = start, right = start;
        while (right - left + 1 < k) {
            if (left <= 0 || (right + 1 < arr.size() && abs(arr[left - 1] - x) > abs(arr[right + 1] - x))) {
                right += 1;
            } else {
                left -= 1;
            }
        }
        vector<int> res;
        for (int i = left; i <= right; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = (int)arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        vector<int> res;
        for (int i = left; i < left + k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};