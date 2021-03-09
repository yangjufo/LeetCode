class Solution {
public:
    unordered_map<int, int> boPairs = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}
    };
    bool isStrobogrammatic(string num) {
        int left = 0, right = num.length() - 1;        
        while (left <= right) {
            if (left == right) return num[left] == '1' || num[left] == '0' || num[left] == '8';
            if (boPairs.find(num[left]) == boPairs.end() || boPairs[num[left]] != num[right]) return false;
            left++;
            right--;
        }
        return true;
    }        
};