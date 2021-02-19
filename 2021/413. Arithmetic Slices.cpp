class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), count = 0, prev = 0;
        for (int i = 3; i <= n; i++) {
            if (A[i - 1] - A[i - 2] == A[i - 2] - A[i - 3]) {
                count += prev + 1;                
                prev += 1;
            } else {
                prev = 0;
            }
        }
        return count;
    }
};