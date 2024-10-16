class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> windows(nums.begin(), nums.begin() + k);
        vector<double> res;
        auto mid = next(windows.begin(), k / 2);
        for (int i = k;; i++) {
            res.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);
            if (i == nums.size()) {
                break;
            }
            windows.insert(nums[i]);

            if (nums[i] < *mid) {
                mid--;
            }
            if (nums[i - k] <= *mid) {
                mid++;
            }
            windows.erase(windows.find(nums[i - k]));
        }
        return res;
    }
};