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