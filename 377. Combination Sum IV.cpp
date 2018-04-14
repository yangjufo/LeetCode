class Solution {
public:
    int getCombination(vector<int>& nums, vector<int>& combs, int target){
        if (combs[target] != -1)
            return combs[target];
        int res = 0;        
        for(int i = 0; i < nums.size(); i++){                        
            if(target >= nums[i])
                res += getCombination(nums, combs, target - nums[i]);
        }        
        combs[target] = res;
        return res;
    }        
    int combinationSum4(vector<int>& nums, int target) {                                
        vector<int> comb;
        comb.resize(target + 1, -1);     
        comb[0] = 1;
        int res = getCombination(nums, comb, target);
        return res;
    }
};