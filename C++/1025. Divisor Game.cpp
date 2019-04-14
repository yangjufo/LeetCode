class Solution {
public:
    bool divisorGame(int N) {
        bool alice = false;
        while (N != 1) {
            int i = 1;
            for (; i < N; i++) {
                if (N % i == 0){
                    N = N - i;
                    alice = !alice;
                    break;
                }                
            }
            if (i == N)
                break;
        }
        return alice;
    }
};