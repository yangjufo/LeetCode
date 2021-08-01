class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long count = 0, side = 1;
        for (; ; side ++) {
            count += side * side * 2 * 4 + (1 + side) * side / 2 * 8 - 4 * side;
            if (count >= neededApples) {
                break;
            }
        }
        return side * 8;
    }
};