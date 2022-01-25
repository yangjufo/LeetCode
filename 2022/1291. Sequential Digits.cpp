class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string base = "123456789", strLow = to_string(low), strHigh = to_string(high);
        int lowDigit = 0, highDigit = 0;
        while (low > 0) {
            lowDigit++;
            low /= 10;
        }
        while (high > 0) {
            highDigit++;
            high /= 10;
        }
        vector<int> res;
        for (int i = 0; i + lowDigit <= 9; i++) {
            string sub = base.substr(i, lowDigit);
            if (sub < strLow) {
                continue;
            }
            if (lowDigit == highDigit && sub > strHigh) {
                break;
            }
            res.push_back(stoi(sub));
        }
        for (int i = lowDigit + 1; i < highDigit; i++) {
            for (int j = 0; j + i <= 9; j++) {
                res.push_back(stoi(base.substr(j, i)));
            }
        }
        for (int i = 0; highDigit > lowDigit && i + highDigit <= 9; i++) {
            string sub = base.substr(i, highDigit);
            if (sub > strHigh) {
                break;
            }
            res.push_back(stoi(sub));
        }
        return res;
    }
};