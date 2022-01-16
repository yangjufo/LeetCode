class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 1) {
                target -= 1;
                count += 1;
            }
            target /= 2;
            maxDoubles -= 1;
            count++;
        }
        count += target - 1;
        return count;
    }
};