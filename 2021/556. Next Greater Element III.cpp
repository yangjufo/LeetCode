class Solution {
public:
    int nextGreaterElement(int n) {
        if (n == INT_MAX) return -1;
        string nStr = to_string(n);
        int i = (int)nStr.length() - 1;
        while (i > 0 && nStr[i] <= nStr[i - 1]) {
            i--;
        }
        if (i == 0) return -1;
        int j = i;
        for (int k = i + 1; k < nStr.length(); k++) {
            if (nStr[k] > nStr[i - 1] && nStr[k] < nStr[j]) {
                j = k;
            }
        }              
        swap(nStr[i - 1], nStr[j]);
        sort(nStr.begin() + i, nStr.end());
        return nStr.length() == to_string(INT_MAX).length() && nStr > to_string(INT_MAX) ? -1 : stoi(nStr);
    }
};