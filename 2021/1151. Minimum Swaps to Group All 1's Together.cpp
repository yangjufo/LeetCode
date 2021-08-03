class Solution {
public:
    int minSwaps(vector<int>& data) {
        int oneCount = 0;
        for (int n : data) {
            if (n == 1) {
                oneCount++;
            }
        }
        int minSwap = oneCount, oneFound = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == 1) {
                oneFound++;
            }
            if (i >= oneCount - 1) {
                if (i >= oneCount && data[i - oneCount] == 1) {
                    oneFound--;
                }
                minSwap = min(minSwap, oneCount - oneFound);                
            }
        }
        return minSwap;
    }
};

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
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == 1) {
                window1++;
            }
            if (i >= total1 - 1) {
                if (i >= total1 && data[i - total1] == 1) {
                    window1--;
                }
                minSwap = min(minSwap, total1 - window1);
            }
        }
        return minSwap;
    }
};