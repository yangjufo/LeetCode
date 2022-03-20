class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            int pos = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    pos += 1;
                    break;
                } else if (nums[j] > nums[i]) {
                    pos -= 1;
                    break;
                }
            }
            for (int j = i + 1; pos != 0 && j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    pos += 1;
                    break;
                } else if (nums[j] > nums[i]) {
                    pos -= 1;
                    break;
                }
            }
            if (pos == 2 || pos == -2) {
                count++;
            }
        }
        return count;
    }
};