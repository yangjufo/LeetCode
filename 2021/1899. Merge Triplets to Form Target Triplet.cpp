class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3, false);
        int count = 0;
        for (vector<int>& t : triplets) {
            if (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                if (!found[0]) count++;
                found[0] = true;
            }
            if (t[1] == target[1] && t[0] <= target[0] && t[2] <= target[2]) {
                if (!found[1]) count++;
                found[1] = true;
            }
            if (t[2] == target[2] && t[0] <= target[0] && t[1] <= target[1]) {
                if (!found[2]) count++;
                found[2] = true;
            }
            if (count >= 3) return true;
        }
        return false;
    }
};