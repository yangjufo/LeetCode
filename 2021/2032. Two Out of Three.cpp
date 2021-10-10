class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> count(101, 0);                        
        add(nums1, count);
        add(nums2, count);
        add(nums3, count);
        vector<int> res;
        for (int i = 1; i <= 100; i++) {
            if (count[i] >= 2) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    void add(vector<int>& nums, vector<int>& count) {
        vector<bool> visited(101, false);
        for (int n : nums) {
            if (visited[n]) continue;
            count[n]++;
            visited[n] = true;
        }
    }
};