class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {        
        int left = max(A, E), right = min(G, C), bottom = max(B, F), top = min(H ,D);
        int sum = (D - B) * (C - A) + (H - F) * (G - E);        
        if (right > left && top > bottom) {
            sum -= (right - left) * (top - bottom);
        }
        return sum;
    }
};