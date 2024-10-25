class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string& t : timePoints) {
            minutes.push_back(((t[0] - '0') * 10 + (t[1] - '0')) * 60 +
                              (t[3] - '0') * 10 + (t[4] - '0'));
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = minutes[0] + 24 * 60 - minutes.back();
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        return minDiff;
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> minutes(24 * 60);
        for (string& t : timePoints) {
            int key = (((t[0] - '0') * 10 + (t[1] - '0')) * 60 +
                              (t[3] - '0') * 10 + (t[4] - '0'));
            if (minutes[key]) {
                return 0;
            }
            minutes[key] = true;
        }
        int minDiff = 24 * 60;
        int prevIndex = -1, firstIndex = -1, lastIndex = -1;
        for (int i = 0; i < 24 * 60; i++) {
            if (minutes[i]) {
                if (prevIndex != -1) {
                    minDiff = min(minDiff, i - prevIndex);
                }
                prevIndex = i;
                if (firstIndex == -1) {
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }
        return min(minDiff, firstIndex + 24 * 60 - lastIndex);
    }
};