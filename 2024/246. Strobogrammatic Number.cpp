class Solution {
public:
    unordered_map<char, char> pairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    bool isStrobogrammatic(string num) {
        int left = 0, right = num.length() - 1;
        while (left <= right) {
            if (pairs.find(num[left]) == pairs.end() ||
                pairs[num[left]] != num[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};