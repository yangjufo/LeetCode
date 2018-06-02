class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        int start, end;        
        end = nums.size() - 1;
        start = 0;
        int j = end;
        int flag =  false;
        while(j != 0){
            for(int i = j - 1; i > -1; i--){
                if (nums[i] < nums[j]){                    
                    end  = !flag || i > start ? j : end;
                    start = !flag || i > start ? i : start;  
                    flag = true;
                    break;
                }
            }    
            j--;
        }
        if (flag){
            swap(nums[start], nums[end]);
            sort(&nums[start + 1], &nums[nums.size()-1] + 1);
        }            
        else
            sort(nums.begin(), nums.end());
        
        return;
    }
};