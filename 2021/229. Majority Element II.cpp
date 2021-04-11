class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = nums[0], can2, count1 = 0, count2 = 0;
        for (int n : nums) {
            if (can1 == n) {
                count1++;
            } else if (can2 == n) {
                count2++;
            } else if (count1 == 0) {
                can1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                can2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }            
        }        
        vector<int> res;
        count1 = count2 = 0;
        for (int n : nums) {
            if (n == can1) {
                count1++;
            } else if (n == can2) {
                count2++;
            }
        }
        if (count1 > (nums.size() / 3)) {
            res.push_back(can1);
        }
        if (count2 > (nums.size() / 3)) {
            res.push_back(can2);
        }
        return res;
    }
};