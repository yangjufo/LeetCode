class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {        
        unordered_set<int> intSet;
        for (int xi = 1; xi < bound; xi *= x) {
            for (int yi = 1; xi + yi <= bound; yi *= y) {
                intSet.insert(xi + yi);
                if (y == 1) break;                
            }
            if (x == 1) break;
        }
        return vector<int>(intSet.begin(), intSet.end());
    }
};