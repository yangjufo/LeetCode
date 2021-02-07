class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        while ((a > 0 && b > 0) || (a > 0 && c > 0) || (b > 0 && c > 0)) {
            score++;
            if (a > b || a > c) {
                a--;
                if (b > c) {
                    b--;
                } else {
                    c--;
                }                
            } else {
                b--;
                c--;                
            }            
        }
        return score;
    }
};

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        return min((a + b + c) / 2, a + b + c - max(a, max(b, c)));
    }
};