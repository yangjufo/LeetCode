class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, total = 0;
        for (string row : bank) {
            int count = 0;
            for (char c : row) {
                if (c == '1') {
                    count += 1;
                }
            }
            total += prev * count;
            if (count != 0) {
                prev = count;
            }
        }
        return total;
    }
};