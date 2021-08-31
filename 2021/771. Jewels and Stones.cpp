class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jSet(jewels.begin(), jewels.end());
        int count = 0;
        for (char s : stones) {
            if (jSet.find(s) != jSet.end()) {
                count++;
            }
        }
        return count;
    }
};