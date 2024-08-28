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

class Solution {
public:
    unordered_map<char, int> ri = {{'M', 1000}, {'D', 500}, {'C', 100},
                                   {'L', 50},   {'X', 10},  {'V', 5},
                                   {'I', 1}};
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int flag = 1;
            if (i + 1 < s.length() && ri[s[i]] < ri[s[i + 1]]) {
                flag = -1;
            }
            num += flag * ri[s[i]];
        }
        return num;
    }
};