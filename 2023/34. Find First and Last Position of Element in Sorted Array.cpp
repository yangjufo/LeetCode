class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid + 1;
} else {
    right = mid;
}
        }
        if (left >= nums.size() || nums[left] > target) {
            return {-1, -1};
}
        int first = left;
        left = 0, right = (int)nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
               left = mid + 1;
} else {
      right = mid;
            }
}
   return {first, left - 1};
    }
};