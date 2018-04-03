class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start, end, mid;
        start = 0; 
        end = nums.size() - 1;\
        while(start <= end){
            mid = (start + end) / 2;            
            if (nums[mid] > target) {
                if (target < nums[start] && nums[mid] > nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;                                                    
            }
            else if (nums[mid] < target){
                if (target > nums[end] && nums[mid] < nums[end])
                    end = mid - 1;
                else if (target < nums[end] || nums[mid] > nums[end]){
                    start = mid + 1;
                }                    
                else if(target == nums[end])
                    return end;
                else                    
                    return -1;
            }               
            else
                return mid;
            
        }        
        return -1;
    }
};