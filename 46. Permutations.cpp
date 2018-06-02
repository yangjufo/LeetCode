class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> premution;      
        premute(nums, premution, res);
        return res;
    }
    
private:
    void premute(vector<int>&nums, vector<int>& premution, vector<vector<int>>& res){
        if (nums.size() == 0){            
            res.push_back(premution);
            return;
        }             
        int length = nums.size();        
        for (int i = 0; i < length; i++){
            premution.push_back(nums[i]);                               
            int tmp = nums[i];
            swap(nums[i], nums[length - 1]);
            nums.pop_back();
            premute(nums, premution, res);
            nums.push_back(tmp);
            swap(nums[length - 1], nums[i]);
            premution.pop_back();
        }
            
    }
};
