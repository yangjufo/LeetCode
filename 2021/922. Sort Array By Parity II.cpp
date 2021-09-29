class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIndex = 1, evenIndex = 0;
        while (oddIndex < nums.size() && evenIndex < nums.size()) {
            while (oddIndex < nums.size() && nums[oddIndex] % 2 == 1) {
                oddIndex+= 2;
            }
            while (evenIndex < nums.size() && nums[evenIndex] % 2 == 0) {
                evenIndex += 2;
            }
            if (oddIndex < nums.size() && evenIndex < nums.size()) {
                swap(nums[oddIndex], nums[evenIndex]);
                oddIndex += 2;
                evenIndex += 2;
            }
        }
        return nums;
    }
};