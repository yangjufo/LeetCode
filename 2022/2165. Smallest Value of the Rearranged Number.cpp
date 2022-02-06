class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> count(10, 0);
        bool pos = true;
        if (num < 0) {
            pos = false;
            num = -num;
        }
        while (num != 0) {
            count[num % 10] += 1;
            num /= 10;
        }
        long long res = 0;
        if (pos) {
            int first = 1;
            while (first < 10 && count[first] == 0) {
                first++;
            }
            if (first == 10) {
                return 0;
            }
            res = first;
            count[first]--;
            for (int i = 0; i <= 9; i++) {
                for (int c = 0; c < count[i]; c++) {
                    res = res * 10 + i;
                }
            }
        } else {
            for (int i = 9; i >= 0; i--) {
                for (int c = 0; c < count[i]; c++) {
                    res = res * 10 + i;
                }
            }
            res = -res;
        }
        return res;
    }
};