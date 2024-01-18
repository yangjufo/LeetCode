class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int n : arr) {
            counts[n]++;
        }
        unordered_set<int> freq;
        for (auto& [_, f] : counts) {
            if (freq.find(f) != freq.end()) {
                return false;
            }
            freq.insert(f);
        }
        return true;
    }
};