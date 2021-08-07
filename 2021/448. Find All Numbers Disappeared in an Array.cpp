class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i + 1) continue;
            int index = nums[i] - 1;
            nums[i] = -1;
            while (index >= 0 && nums[index] != index + 1) {
                int next = nums[index] - 1;
                nums[index] = index + 1;
                index = next;
            }            
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};