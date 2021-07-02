class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (pos >= arr.size()) {
            pos = (int)arr.size() - 1;
        }
        if (pos > 0 && x - arr[pos - 1] <= arr[pos] - x) {
            pos--;
        }
        int left = pos, right = pos;   
        while (right -left + 1 < k) {
            if (left <= 0 || (right + 1 < arr.size() && arr[right + 1] - x < x - arr[left - 1])) {
                right++;
            } else {
                left--;
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
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }            
        }
        vector<int> res;
        for (int i = left; i < left + k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};