class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> numMap;
        for (int n : nums) {
            numMap[n] += 1;
        }
        for (auto& [left, right] : numMap) {
            if (numMap.find(k - left) != numMap.end()) {
                int c = min(right, numMap[k - left]);
                if (k - left == left) {
                    c = right / 2;
                }
                count += c;
                numMap[left] -= c;
                numMap[k - left] -= c;
            }
        }
        return count;
    }
};