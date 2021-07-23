class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> leftSet;
            for (int n : nums) {
                leftSet.insert(n & mask);
            }
            
            int nextTry = res | (1 << i);
            for (int left : leftSet) {
                if (leftSet.find(left ^ nextTry) != leftSet.end()) {
                    res = nextTry;
                    break;
                }
            }
        }
        return res;
    }
};