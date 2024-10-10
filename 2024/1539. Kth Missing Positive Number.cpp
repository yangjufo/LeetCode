class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            int missing = (i == 0) ? arr[i] - 1 : arr[i] - arr[i - 1] - 1;

            if (missing >= k) {
                return (i == 0) ? k : arr[i - 1] + k;
            }
            k -= missing;
        }
        return arr.back() + k;
    }
};