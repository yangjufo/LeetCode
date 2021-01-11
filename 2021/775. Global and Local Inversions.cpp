class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int minVal = A.size();
        for (int i = A.size() - 1; i >= 2; i--) {
            minVal = min(minVal, A[i]);
            if (A[i - 2] > minVal) return false;
        }
        return true;
    }
};