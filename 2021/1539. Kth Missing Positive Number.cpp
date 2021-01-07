class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int curr = 0, count = 0;
        for (int i = 0; i < arr.size(); i++) {
            int diff = arr[i] - curr - 1;
            if (count + diff >= k) {
                return curr + (k - count);
            }
            count += arr[i] - curr - 1;
            curr = arr[i];                        
        }
        return curr + (k - count);
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }            
        }
        return left + k;
    }
};