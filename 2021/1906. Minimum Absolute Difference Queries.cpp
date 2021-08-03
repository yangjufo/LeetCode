class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> indexes(101, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            indexes[nums[i]].push_back(i);
        }    
        vector<int> res;
        for (vector<int>& q : queries) {
            res.push_back(getMinDiff(indexes, q[0], q[1]));
        }
        return res;
    }
    
    int getMinDiff(vector<vector<int>>& indexes, int left, int right) {
        int prev = -1, minDiff = 100;
        for (int i = 1; i <= 100 && minDiff > 1; i++) {            
            if (!indexes[i].empty()) {
                int leftIndex = lower_bound(indexes[i].begin(), indexes[i].end(), left) - indexes[i].begin();
                int rightIndex = lower_bound(indexes[i].begin(), indexes[i].end(), right) - indexes[i].begin();
                if (leftIndex >= indexes[i].size() || indexes[i][leftIndex] > right) continue;
                if (rightIndex < indexes[i].size() && indexes[i][rightIndex] < left)  continue;
                if (prev != -1) {
                    minDiff = min(minDiff, i - prev);
                }
                prev = i;
            }
        }
        return minDiff == 100 ? -1 : minDiff;
    }        
};

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> preCount(nums.size() + 1, vector<int>(101, 0));
        vector<int> count(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            for (int j = 1; j <= 100; j++) {
                preCount[i + 1][j] = count[j];
            }
        }
        vector<int> res;
        for (vector<int>& q : queries) {
            vector<int> tmp(101, 0);
            for (int i = 1; i <= 100; i++) {
                tmp[i] += preCount[q[1] + 1][i] - preCount[q[0]][i];
            }
            int prev = -1, minDiff = 100;
            for (int i = 1; i <= 100; i++) {
                if (tmp[i] == 0) continue;
                if (prev != -1) {
                    minDiff = min(minDiff, i - prev);
                }
                prev = i;
            }
            res.push_back(minDiff == 100 ? -1 : minDiff);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> count(nums.size() + 1, vector<int>(101));
        for (int i = 0; i < nums.size(); i++) {            
            count[i + 1] = count[i];
            count[i + 1][nums[i]]++;            
        }
        vector<int> res;
        for (vector<int>& q : queries) {
            int prev = -100, minDiff = 100;
            for (int i = 1; i <= 100 && minDiff > 0; i++) {
                if (count[q[1] + 1][i] - count[q[0]][i] > 0) {
                    minDiff = min(minDiff, abs(i - prev));
                    prev = i;
                }                
            }            
            res.push_back(minDiff == 100 ? -1 : minDiff);
        }
        return res;
    }
};