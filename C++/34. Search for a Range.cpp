class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = -1;
        vector<int> res = {-1, -1};
        while (start <= end){
            mid = (start + end) / 2;            
            if (nums[mid] > target){                
                end = mid - 1;
            }
            else if(nums[mid] <target){
                start = mid + 1;
            }
            else{                                
                start = end = mid;
                while (start > -1 && nums[start] == target)
                    start--;
                while (end < nums.size() && nums[end] == target)
                    end++;
                res[0] = start + 1;
                res[1] = end - 1;
                break;
            }                            
        }                
        return res;
    }    
};