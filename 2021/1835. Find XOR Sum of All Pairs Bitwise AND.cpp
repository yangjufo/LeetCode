class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res1 =arr1[0], res2 = arr2[0];
        for (int i = 1; i < arr1.size(); i++) {
            res1 ^= arr1[i];
        }
        for (int i = 1; i < arr2.size(); i++) {
            res2 ^= arr2[i];
        }
        return res1 & res2;
    }
};