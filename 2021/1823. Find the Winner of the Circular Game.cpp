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

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> seats(n, true);
        int removed = 0, index = 0;
        while (removed + 1 < n) {
            int count = 0;
            while (count < k) {
                if (seats[index]) {
                    count++;
                }
                index = (index + 1) % n;
            }
            seats[(index + n - 1) % n] = false;
            removed++;
        }
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = (res + k) % i;
        return res + 1;
    }
};