class Solution {
private:
    unordered_map<char, int> nums {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int res = 0, curr = nums[s[0]];
        for (int i = 1; i < s.length(); i++) {
            if (nums[s[i]] > nums[s[i - 1]]) {
                res += nums[s[i]] - curr;
                curr = 0;
            } else if (nums[s[i]] < nums[s[i - 1]]){
                res += curr;
                curr = nums[s[i]];
            } else {
                curr += nums[s[i]];
            }
        }
        return res + curr;
    }
};
