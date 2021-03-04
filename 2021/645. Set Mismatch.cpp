class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) continue;            
            int tmp = nums[i];
            nums[i] = 0;
            while (tmp > 0) {
                int index = tmp - 1;
                tmp = nums[index];
                nums[index] = nums[index] >= 0 ? -1 : -2;
            }
        }
        
        vector<int> res = {0, 0};
        for (int i = 0; i < nums.size() && (res[0] == 0 || res[1] == 0); i++) {
            if (nums[i] == 0) res[1] = i + 1;
            if (nums[i] == -2) res[0] = i + 1;
        }
        
        return res;
    }
};