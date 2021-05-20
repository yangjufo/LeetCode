class Solution {
public:
    int minMoves2(vector<int>& nums) {        
        sort(nums.begin(), nums.end());
        int moves = 0, mid = nums[nums.size() / 2];
        for (int i = 0; i < nums.size(); i++) {
            moves += abs(nums[i] - mid);
        }
        return moves;
    }
};