class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());        
        int left = 0, right = (int)nums.size() - 1;
        bool putLeft = true;
        vector<int> res;
        while (res.size() < nums.size()) {
            if (putLeft) {
                res.push_back(nums[left]);
                left++;
            } else {
                res.push_back(nums[right]);
                right--;
            }
            putLeft = !putLeft;
        }
        return res;
    }
};