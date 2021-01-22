class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> subMax;
        vector<int> most;
        for (int i = 0; i < nums.size(); i++) {
            while (!subMax.empty() && subMax.back() > nums[i]) {
                subMax.pop_back();
            }
            subMax.push_back(nums[i]);
            if (i >= nums.size() - k) {                
                most.push_back(subMax.front());
                subMax.pop_front();
            }            
        }
        return most;
            
    }
};
