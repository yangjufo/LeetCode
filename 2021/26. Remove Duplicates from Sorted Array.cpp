class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[start] = nums[i];
                start++;
            }
        }
        return start;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) count++;
            else nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};