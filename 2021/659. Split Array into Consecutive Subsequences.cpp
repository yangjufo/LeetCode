class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        for (int n : nums){
            left[n]++;
        }
        for (int n : nums) {
            if (left[n] == 0) {
                continue;
            }
            left[n]--;
            if (end[n - 1] > 0) {
                end[n - 1]--;
                end[n]++;
            } else if (left[n + 1] > 0 && left[n + 2] > 0) {
                left[n + 1]--;
                left[n + 2]--;
                end[n + 2]++;
            } else {
                return false;
            }            
        }
        return true;
    }
};