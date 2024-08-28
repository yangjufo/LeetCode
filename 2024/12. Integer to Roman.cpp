class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> nums = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        string roman;
        for (int i = 0; i < nums.size() && num > 0; i++) {
            while (num >= nums[i].first) {
                roman += nums[i].second;
                num -= nums[i].first;
            }
        }
        return roman;
    }
};