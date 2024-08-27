class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = INT_MAX, count = 0;
        for (int n : nums) {
            if (count == 0) {
                cand = n;
            }
            if (cand == n) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return cand;
    }
};