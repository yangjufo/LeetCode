class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int pIndex = 0, nIndex = 1;
        for (int n : nums) {
            if (n > 0) {
                res[pIndex] = n;
                pIndex += 2;
            } else {
                res[nIndex] = n;
                nIndex += 2;
            }
        }
        return res;
    }
};