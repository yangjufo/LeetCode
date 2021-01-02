class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> sCount;
        for (char c : s) {
            sCount[c]++;
        }
        int singleCount = 0;
        for (auto const& iter : sCount) {
            if ((iter.second & 0x1) == 1) {
                singleCount++;  
                if (singleCount > 1)
                     return false;
            }            
        }
        return true;
    }
};