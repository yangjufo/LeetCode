class Solution {
public:
    int minDeletions(string s) {
        vector<int> counts(26);
        for (char c : s) {
            counts[c - 'a']++;
        }
        unordered_set<int> nums;
        int total = 0;
        for (int c : counts) {
            if (c == 0) {
                continue;
            }
            int n = c, diff = 0;
            while (nums.find(c - diff) != nums.end() && c - diff > 0) {
                diff++;
            }
            total += diff;
            if (c - diff != 0) {
                nums.insert(c - diff);
            }
        }
        return total;
    }
};