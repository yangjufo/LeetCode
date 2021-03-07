class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long rem = goal;
        for (int n : nums) {
            rem -= n;
        }
        if (rem < 0) rem = -rem;
        return (rem + limit - 1) / limit;
    }
};