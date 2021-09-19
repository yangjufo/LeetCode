class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (string& op : operations) {
            if (op[0] == '+' || op.back() == '+') {
                res++;
            } else {
                res--;
            }
        }
        return res;
    }
};