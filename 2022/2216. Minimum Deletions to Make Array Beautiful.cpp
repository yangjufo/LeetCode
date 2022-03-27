class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count = 0, index = 0;
        while (index < nums.size()) {
            if (index + 1 == nums.size()) {
                count++;
                index++;
            } else {
                if (nums[index] != nums[index + 1]) {
                    index += 2;
                } else {
                    if (index + 2 < nums.size() && (nums[index] != nums[index + 2] || nums[index + 1] != nums[index + 2])) {
                        count++;
                        index += 3;
                    } else {
                        count += 2;
                        index += 2;
                    }
                }
            }

        }
        return count;
    }
};