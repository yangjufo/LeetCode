class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < (int)nums.size() - 1 && nums[i] != 0; j++) {
                while (k < (int)nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); i++) {
            for (int j = i + 1; j + 1 < nums.size(); j++) {
                int start = upper_bound(nums.begin() + j + 1, nums.end(), nums[j] - nums[i]) - nums.begin();
                int end = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
                count += max(end - start, 0);
            }
        }
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); i++) {
            int k = i + 2;
            for (int j = i + 1; j + 1 < nums.size() && nums[i] != 0; j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};