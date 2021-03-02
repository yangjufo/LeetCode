class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> indexes;
        for (int i = 0; i < keyboard.length(); i++) {
            indexes[keyboard[i]] = i;
        }
        
        int lastPos = 0, time = 0;
        for (char c : word) {
            time += abs(indexes[c] - lastPos);
            lastPos = indexes[c];
        }
        return time;
    }
};