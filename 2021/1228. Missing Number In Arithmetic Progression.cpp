class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int firstDiff = arr[1] - arr[0], secondDiff = arr[2] - arr[1];        
        if (abs(firstDiff) < abs(secondDiff)) {
            return arr[1] + firstDiff;
        } 
        if (abs(firstDiff) > abs(secondDiff)) {
            return arr[1] - secondDiff;
        } 
        for (int i = 3; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != firstDiff) {
                return arr[i - 1] + firstDiff;
            }
        }
        return arr[0];
    }
};