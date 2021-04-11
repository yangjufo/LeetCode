class Solution {
public:
    vector<string> res;
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};                
        int left = nums[0], right = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                right = nums[i];
            } else {                
                addToRes(left, right);
                left = right = nums[i];
            }
        }
        addToRes(left, right);
        return res;
    }
    
    void addToRes(int left, int right) {
        if (left == right) {
            res.push_back(to_string(left));
        } else {
            res.push_back(to_string(left) + "->" + to_string(right));
        }
    }
};