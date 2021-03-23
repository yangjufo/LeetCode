class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> counter = count(N);
        for (int i = 0; i < 31; i++) {
            if (counter == count(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> count(int N) {
        vector<int> counter(10, 0);
        while (N > 0) {
            counter[N % 10]++;
            N /= 10;
        }
        return counter;
    }
};