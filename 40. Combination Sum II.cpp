class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
    
private:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>combination, int begin){
        if (!target){
            res.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){                        
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i + 1);
            combination.pop_back();            
            while (candidates[i] == candidates[i + 1])
                i += 1;
        }        
    }    
};
