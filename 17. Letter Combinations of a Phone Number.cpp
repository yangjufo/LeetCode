class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string num_letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        vector<int> nums;
        vector<string> tmp;
        if (digits.length() == 0)
            return res;
        for (char digit : digits) {
            nums.push_back(digit - '0');
        }
        res.emplace_back("");
        for (int num : nums) {
            for (char j : num_letter[num]) {
                for (const auto &re : res) {
                    tmp.push_back(re + j);
                }
            }
            res.swap(tmp);
            tmp.clear();
        }
        return res;
    }
};