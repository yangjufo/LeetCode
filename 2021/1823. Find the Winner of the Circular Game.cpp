class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> left(n + 1, false);
        int i = 1, total = n;
        k = k % (n + 1);
        while (total > 1) {            
            int count = 0, prev = i;
            while (count < k) {
                i = i % n;
                if (left[i] == false) {
                    prev = i;
                    count++;
                }
                i++;
            }
            left[prev] = true;
            total--;
        }
        for (int i = 1; i <= n; i++) {
            if (left[i] == false) return i;
        }
        return -1;
    }
};