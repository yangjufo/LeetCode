class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        bool start = true;
        while (start || slow != fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            start = false;
        }
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};