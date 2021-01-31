class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(highLimit + 1, 0);                
        vector<int> boxes(50, 0);
        int ans = 0;
        for (int i = 1; i <= highLimit; i++) {                        
            count[i] = i % 10 + count[i / 10];
            if (i >= lowLimit) {
                boxes[count[i]]++;
                ans = max(ans, boxes[count[i]]);
            }
        }
        return ans;
    }
};