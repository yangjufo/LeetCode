class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size(), num = 0;
        vector<int> counts(n, -1);
        for (int i = 0; i < rows; i++) {
            int start = num % n;
            if (counts[start] < 0) {
                int len = 0, cnt = 0;
                for (int j = start;len < cols; j = (j + 1) % n, cnt++) {
                    if (len + sentence[j].length() > cols) {
                        break;
                    }
                    len += sentence[j].length() + 1;
                }            
                num += cnt;
                counts[start] = cnt;                
            } else {
                num += counts[start];
            }
        }
        return num / n;
    }
};