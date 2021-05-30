class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int tmp = 0;
        int start = 0;
        unordered_map<int, int> numIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numIndexMap.count(nums[i])) {
                while (start <= numIndexMap[nums[i]]) {
                    tmp -= nums[start];
                    start++;
                }
            }
            numIndexMap[nums[i]] = i;
            tmp += nums[i];
            res = tmp > res ? tmp : res;            
        }
        return res;
    }
};

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0, sum = 0, maxSum = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count[nums[i]]++;
            while (count[nums[i]] > 1 && start < i) {
                count[nums[start]]--;
                sum -= nums[start];
                start++;
            }
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};