class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxW = w - verticalCuts.back(), maxH = h - horizontalCuts.back();
        for (int i = 0; i < horizontalCuts.size(); i++) {
            maxH = max((i == 0 ? horizontalCuts[i] : horizontalCuts[i] - horizontalCuts[i - 1]), maxH);
        }
        for (int i = 0; i < verticalCuts.size(); i++) {
            maxW = max((i == 0 ? verticalCuts[i] : verticalCuts[i] - verticalCuts[i - 1]), maxW);
        }
        return (long)(maxH % 1'000'000'007) * (maxW % 1'000'000'007) % 1'000'000'007;
    }
};