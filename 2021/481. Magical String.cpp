class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;
        vector<int> seq(n + 1, 0);
        seq[0] = 1, seq[1] = 2, seq[2] = 2;
        int head = 2, tail = 3, num = 1, count = 1;
        while (tail < n) {
            for (int i = 0; i < seq[head]; i++) {
                seq[tail] = num;
                if (num == 1 && tail < n) {
                    count++;
                }
                tail++;
            }
            num = 3 - num;
            head++;
        }
        return count;
    }
};