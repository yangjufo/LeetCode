class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        int count = 1, res = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                if (i == 1 || arr[i - 1] < arr[i - 2]) {
                    count++;
                } else {
                    count = 2;
                }
            } else if (arr[i] < arr[i - 1]) {
                if (i == 1 || arr[i - 1] > arr[i - 2]) {
                    count++;
                } else {
                    count = 2;
                }
            } else {
                count = 1;
            }            
            res = max(count, res);
        }
        return res;
    }
};