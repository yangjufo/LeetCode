class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = 0;
        for (int a : arr) {
            if (a == 1) ones++;
        }
        if (ones == 0) {
            return {0, (int)arr.size() - 1};
        }
        if (ones % 3 != 0) {
            return {-1, -1};
        }
        int start = 0;
        while (start < arr.size() && arr[start] != 1) {
            start++;
        }
        int mid = start, midCount = 0;
        while (mid < arr.size()) {
            if (arr[mid] == 1) {
                midCount++;
            }
            if (midCount > ones / 3) {
                break;
            }
            mid++;
        }
        int end = mid, endCount = 0;
        while (end < arr.size()) {
            if (arr[end] == 1) {
                endCount++;
            }
            if (endCount > ones / 3) {
                break;
            }
            end++;
        }
        while (end < arr.size() && arr[start] == arr[mid] && arr[mid] == arr[end]) {
            start++;
            mid++;
            end++;
        }
        if (end >= arr.size()) {
            return {start - 1, mid};
        }
        return {-1, -1};
    }
};