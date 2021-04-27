class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> gaps;
        int pos = 0;
        for (; pos + 1 < heights.size(); pos++) {
            if (heights[pos + 1] <= heights[pos]) continue;
            int diff = heights[pos + 1] - heights[pos];
            gaps.push(diff);
            bricks -= diff;
            if (bricks < 0) {
                if (ladders <= 0) break;
                bricks += gaps.top();
                gaps.pop();
                ladders--;
            }
        }
        return pos;
    }
};
