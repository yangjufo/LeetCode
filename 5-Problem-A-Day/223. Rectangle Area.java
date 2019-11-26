class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = Math.min(G, C) > Math.max(E, A) ? (Math.min(G, C) - Math.max(E, A)) : 0;
        int y = Math.min(D, H) > Math.max(B, F) ? (Math.min(D, H) - Math.max(B, F)) : 0;
        return (D - B) * (C - A) + (G - E) * (H - F) - x * y;

    }
}
