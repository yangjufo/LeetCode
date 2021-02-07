class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        int sum = 0;
        for (auto& iter : counter) {
            if (iter.second == 1) {
                sum += iter.first;
            }
        }
        return sum;
    }
};