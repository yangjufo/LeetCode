class Solution {
public:
    bool winnerOfGame(string colors) {
        int aCount = 0, bCount = 0;
        int aStart = -1, bStart = -1;
        for (int i = 0; i < colors.length(); i++) {
            if (colors[i] == 'A') {
                if (bStart != -1) {
                    bCount += max(i - bStart - 2, 0);
                    bStart = -1;
                }
                if (aStart == -1) {
                    aStart = i;
                } else if (i + 1 == colors.length()) {
                    aCount += (i - aStart - 1);
                }
            }
            if (colors[i] == 'B') {
                if(aStart != -1) {
                    aCount += max(i - aStart - 2, 0);
                    aStart = -1;
                }
                if (bStart == -1) {
                    bStart = i;
                } else if (i + 1 == colors.length()) {
                    bCount += (i - bStart - 1);
                }
            }
        }
        return aCount > bCount;
    }