class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, "", 0, target, 0, 0, res);
        return res;
    }

    void backtrack(string& num, string s, int index, int target, long long sum, long long prev, vector<string>& res) {
        if (index >= num.length()) {
            if (sum == target) {
                res.push_back(s);
            }
            return;
        }
        long long currVal = 0;
        string currS;
        for (int i = index; i < num.length(); i++) {
            currVal = currVal * 10 + num[i] - '0';
            currS += num[i];
            if (i != index && currS[0] == '0') {
                break;
            }
            if (index == 0) {
                backtrack(num, currS, i + 1, target, currVal, currVal, res);
            } else {
                backtrack(num, s + "+" + currS, i + 1, target, sum + currVal, currVal, res);
                backtrack(num, s + "-" + currS, i + 1, target, sum - currVal, -currVal, res);
                backtrack(num, s + "*" + currS, i + 1, target, sum - prev + prev * currVal, prev * currVal, res);
            }
        }
    }
};