class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());        
        int lo, hi, sum;
        int offset, tmp_target, flag;        
        offset = 0;
        flag = 1;
        while(true){
            tmp_target = target + flag * offset;
            if (flag > 0)
                offset += 1;
            flag = - flag;
            for (int i = 0; i < nums.size() - 2; i++) {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                    lo = i + 1;
                    hi = static_cast<int>(nums.size() - 1);
                    sum = tmp_target - nums[i];
                    while (lo < hi) {
                        if (nums[lo] + nums[hi] == sum) {
                           return tmp_target;
                        } else if (nums[lo] + nums[hi] < sum) {
                            while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                            lo++;
                        } else {
                            while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                            hi--;
                        }
                    }
                }
            }
        }
        return tmp_target;
    }
};