class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end(), greater<int>());
        
        int index = 0;
        
        for (int i = 1; i < nums.size(); i += 2) {
            nums[i] = tmp[index];
            index++;
        }
        
        for (int i = 0; i < nums.size(); i += 2) {
            nums[i] = tmp[index];
            index++;
        }
    }
};