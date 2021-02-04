class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxNums;
        deque<int> indexes;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {            
            while (!indexes.empty() && indexes.front() <= i - k) {
                maxNums.pop_front();
                indexes.pop_front();
            }
            while (!maxNums.empty() && maxNums.back() < nums[i]) {
                maxNums.pop_back();
                indexes.pop_back();
            }
            maxNums.push_back(nums[i]);
            indexes.push_back(i);
            if (i >= k - 1) {
                res.push_back(maxNums.front());
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indexes;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {            
            while (!indexes.empty() && indexes.front() <= i - k) {
                indexes.pop_front();
            }
            while (!indexes.empty() && nums[indexes.back()] < nums[i]) {
                indexes.pop_back();
            }
            indexes.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[indexes.front()]);
            }
        }
        return res;
    }
};