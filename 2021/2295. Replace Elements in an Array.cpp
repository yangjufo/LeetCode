class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> nm;
        for (int i = 0; i < nums.size(); i++) {
            nm[nums[i]] = i;
        }
        for (vector<int>& op : operations) {
            if (nm.find(op[0]) != nm.end()) {
                nums[nm[op[0]]] = op[1];
                nm[op[1]] = nm[op[0]];
                nm.erase(op[0]);
            }
        }
        return nums;
    }
};