class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ret;
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            int sum = carry + digits[i];
            ret.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) {
            ret.push_back(carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};