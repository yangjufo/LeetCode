class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for (int n : nums) {
            numCount[n]++;
        }
        
        int count = 0;
        for (auto iter : numCount) {
            if (k > 0 && numCount.find(iter.first + k) != numCount.end()) {
                count++;
            } else if (k == 0 && iter.second > 1) {
                count++;
            }
        }
        return count;
    }
};