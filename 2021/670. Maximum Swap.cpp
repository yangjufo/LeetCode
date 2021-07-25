class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int maxCand = (int)numStr.length() - 1, maxIndex = (int)numStr.length() - 1, minIndex = (int) numStr.length() - 1;
        for (int i = (int)numStr.length() - 1; i >= 0; i--) {
            if (numStr[i] > numStr[maxCand]) {
                maxCand = i;
            }
            if (numStr[i] < numStr[maxCand]) {
                minIndex = i;
                maxIndex = maxCand;
            }
        }        
        swap(numStr[minIndex], numStr[maxIndex]);
        return stoi(numStr);
    }
};