class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int max_length[nums.size()];
        max_length[0] = 1;        
        int res = 1;
        int tmp_length;
        for (int i = 1; i < nums.size(); i++){
            max_length[i] = 1;
            for (int j = i - 1; j > -1;  j--){
                if (nums[i] > nums[j]){
                    tmp_length = max_length[j] + 1;
                    max_length[i] = tmp_length > max_length[i] ? tmp_length : max_length[i];                                        
                    res = tmp_length > res ? tmp_length : res;
                }
            }                            
        }
        return res;
    }
};