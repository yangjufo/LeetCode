class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        res.push_back(subset);
        subsets(res, subset, 0, 1, nums);
        return res;  
    }
private:
    void subsets(vector<vector<int>>& res, vector<int> subset, int begin, int length, vector<int>& nums){
        if (length == nums.size() + 1)
            return;
        for (int i = begin; i < nums.size(); i++){
            subset.push_back(nums[i]);
            res.push_back(subset);
            subsets(res, subset, i + 1, length + 1, nums);
            subset.pop_back();
            while (i < nums.size() && nums[i + 1] == nums[i])
                i += 1;
        }
    }   
};