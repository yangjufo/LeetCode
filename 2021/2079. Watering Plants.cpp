class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0, curr = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (curr < plants[i]) {
                step += i * 2 + 1;
                curr = capacity;
            } else {
                step += 1;
            }            
            curr -= plants[i];
        }
        return step;
    }
};