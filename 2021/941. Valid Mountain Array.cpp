class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int prev = arr[0];
        bool down = false, up = false;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > prev) {
                up = true;
                if (down) return false;
            } else if (arr[i] < prev) {
                down = true;
            } else {
                return false;
            }
            prev = arr[i];
        }
        return down && up;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[1] <= arr[0]) return false;
        bool up = true;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) return false;
            if (up) {
                if (arr[i] < arr[i - 1]) {
                    up = false;
                }
            } else {
                if (arr[i] > arr[i - 1]) {
                    return false;
                }
            }
        }
        return !up;
    }
};