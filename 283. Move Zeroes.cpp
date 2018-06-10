class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)
                pos.push_back(i);
        }
        for(int i = 0; i < pos.size(); i++){
            for (int j = pos[i] - i; j < nums.size() - 1; j++){
                nums[j] = nums[j + 1];
            }
            nums[nums.size() - 1] = 0;
        }
    }
};