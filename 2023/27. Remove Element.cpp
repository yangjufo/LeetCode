class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        for (int n : nums) {
            if (n != val) {
                nums[start] = n;
                start++;
            }
        }
        return start;
    }
};