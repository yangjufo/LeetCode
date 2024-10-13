class Solution {
public:
    int xSum (unordered_map<int, int>& counts, int x) {
        vector<array<int, 2>> cv;
        for (const auto& [k, v] : counts){
            cv.push_back({k, v});
        }
        sort(cv.begin(), cv.end(), [](array<int, 2>& left, array<int, 2>& right) {
            return left[1] == right[1] ? left[0] > right[0] : left[1] > right[1];
        });
        int sum = 0;
        for (int i = 0; i < x && i < cv.size(); i++) {
            sum += cv[i][0] * cv[i][1];
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> counts;
        vector<int >res;
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]] += 1;
            if (i >= k - 1) {
                res.push_back(xSum(counts, x));
                counts[nums[i - k + 1]] -= 1;
            }
        }
        return res;
    }
};