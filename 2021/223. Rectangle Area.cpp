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

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int left = max(ax1, bx1), right = min(ax2, bx2), bottom = max(ay1, by1), top = min(ay2, by2);
        int sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        if (right > left && top > bottom) {
            sum -= (right - left) * (top - bottom);
        }
        return sum;
    }
};