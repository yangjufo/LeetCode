class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        for (int i = 0; i < volume; i++) {
            int curr = k;
            while (curr > 0 && heights[curr] >= heights[curr - 1]) {
                curr--;
            }
            while (curr + 1 < heights.size() && heights[curr] >= heights[curr + 1]) {
                curr++;
            }
            while (curr > k && heights[curr] >= heights[curr - 1]) {
                curr--;
            }
            heights[curr] += 1;
        }
        return heights;
    }
};