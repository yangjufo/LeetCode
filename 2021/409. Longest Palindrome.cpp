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

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s){
            count[c]++;
        }
        bool single = false;
        int len = 0;
        for (auto& iter : count) {
            if (iter.second % 2 == 0) {
                len += iter.second;
            } else {
                len += iter.second - 1;
                single = true;
            }
        }
        return len + (single ? 1 : 0);
    }
};