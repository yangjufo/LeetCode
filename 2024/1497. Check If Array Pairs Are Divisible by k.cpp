class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remains;
        for (int a : arr) {
            remains[(a % k + k) % k] += 1;
        }
        for (auto& [num, re] : remains) {
            if ((num == 0 && re % 2 != 0) || (num != 0 && remains[k - num] != re)) {
                return false;
            }
        }
        return true;
    }
};