class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odds, evens;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                evens.push_back(nums[i]);
            } else {
                odds.push_back(nums[i]);
            }
        }
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end());
        int index = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            nums[i] = evens[index];
            index++;
        }
        index = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            nums[i] = odds[index];
            index++;
        }
        return nums;
    }
};