class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> timeCount;
        for (int t : time) {
            timeCount[t % 60]++;
        }
        int res = 0;
        for (auto& iter1 : timeCount) {
            for (auto& iter2 : timeCount) {
                if ((iter1.first + iter2.first) % 60 == 0) {
                    if (iter1.first == iter2.first) {
                        res += iter1.second * (iter2.second - 1) / 2;
                    } else if (iter1.first < iter2.first) {
                        res += iter1.second * iter2.second;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> timeCount;
        int res = 0;
        for (int t : time) {
            if (t % 60 == 0) {
                res += timeCount[0];
            } else {
                res += timeCount[60 - t % 60];
            }
            timeCount[t % 60]++;
        }
        return res;
    }
};