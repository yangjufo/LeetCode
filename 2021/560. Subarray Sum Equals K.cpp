class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;        
        int sum = 0, count = 0;
        sumCount[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];            
            count += sumCount[sum - k];
            sumCount[sum]++;
        }
        
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        int sum = 0, count = 0;
        for (int n : nums) {
            sum += n;            
            count += sumCount[sum - k];
            sumCount[sum]++;
        }
        return count;
    }
};