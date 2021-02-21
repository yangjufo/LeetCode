class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == groups[0][0]) {
                int index = i, j = 0, k = 0;
                while (index < nums.size() && j < groups.size()) {                                                   
                    if (nums[index] != groups[j][k]) {
                        break;
                    }
                    index++;
                    if (k >= groups[j].size() - 1) {                        
                        j++;
                        k = 0;                        
                        while (index < nums.size() && j < groups.size() && nums[index] != groups[j][k]) {                            
                            index++;
                        }
                    } else {
                        k++;
                    }
                }                              
                if (j >= groups.size()) {
                    return true;
                }
            }
        }
        return false;
        
    }
};