class Solution {
public:
    int countCollisions(string directions) {
        string cars;
        int i = 0, count = 0;
        while (i < directions.length()) {
            if (i + 1 < directions.length() && directions[i] == 'R' && directions[i + 1] == 'L') {
                cars += "S";
                i += 2;
                count += 2;
            } else {
                cars += directions[i];
                i += 1;
            }
        }
        bool sFound = false;
        for (char c : cars) {
            if (c == 'L' && sFound) {
                count += 1;
            } else if (c == 'S') {
                sFound = true;
            }
        }
        sFound = false;
        for (int i = (int)cars.length() - 1; i >= 0; i--) {
            if (cars[i] == 'R' && sFound) {
                count += 1;
            } else if (cars[i] == 'S') {
                sFound = true;
            }
        }
        return count;
    }
};