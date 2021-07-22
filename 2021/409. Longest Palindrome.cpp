class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        int even = 0, single = 0;
        for (auto& iter : count) {
            even += iter.second / 2 * 2;
            single = (single == 1 || (iter.second & 0x1) == 1) ? 1 : 0;
        }
        return even + single;
    }
};