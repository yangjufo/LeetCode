class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                count = 1;
            } else {
                count++;
            }           
            if (count <= 2) {
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
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (start < 2 || nums[i] > nums[start - 2]) {
                nums[start] = nums[i];
                start++;
            }
        }
        return start;
    }
};