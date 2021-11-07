class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 0, right = 100000;
        while (left < right) {
            int mid = left + (right -left) / 2;
            if (canPlace(quantities, n, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canPlace(vector<int> quantities, int n, int target) {
        int i = 0;
        while (i < quantities.size() && n >= 0) {
            quantities[i] -= target;
            n--;
            if (quantities[i] <= 0) {
                i++;
            }
        }
        return n >= 0;
    }
};