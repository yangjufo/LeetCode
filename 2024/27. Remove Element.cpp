class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int n : nums) {
            if (n != val) {
                nums[index] = n;
                index++;
            }
        }
        return index;
    }
};