class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        for (int num : candidates){
            int tmp_target = target - num;            
            if (tmp_target < 0)
                continue;
            else if (tmp_target == 0){                
                res.push_back(vector<int>{num});
                continue;
            }                
            else if (tmp_target > 0){
                vector<vector<int>> tmp_ret = combinationSum(candidates, tmp_target);                     
                if (!tmp_ret.empty()){                    
                    for (vector<int> r : tmp_ret){
                        r.push_back(num);
                        res.push_back(r);                        
                    }                    
                }
            }                        
        }
        vector<vector<int>> tmp;
        bool flag;
        for (vector<int> r : res){
            flag = false;
            sort(r.begin(), r.end());
            for (vector<int> t : tmp){
                sort(t.begin(), t.end());
                if (r.size() != t.size())
                    continue;
                int i, j;
                i = j = 0;
                while (i < r.size() && j < t.size()){
                    if (r[i] != t[j])
                        break;                    
                    i++;
                    j++;
                }
                if (i == r.size()){
                    flag =true;    
                    break;
                }
            }            
            if (!flag)
                tmp.push_back(r);
        }
        swap(tmp, res);
        return res;
    }
};
