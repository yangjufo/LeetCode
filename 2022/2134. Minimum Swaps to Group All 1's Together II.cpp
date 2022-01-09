class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total1 = 0;
        for (int n : data) {
            if (n == 1) {
                total1++;
            }
        }
        int minSwap = total1, window1 = 0;
        for (int i = 0; i < data.size() * 2; i++) {
            if (data[i % data.size()] == 1) {
                window1++;
            }
            if (i >= total1 - 1) {
                if (i >= total1 && data[(i - total1) % data.size()] == 1) {
                    window1--;
                }
                minSwap = min(minSwap, total1 - window1);
            }
        }
        return minSwap;
    }
};