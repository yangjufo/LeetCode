class Solution {
public:
    int possibleLen;
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4, 0);
        int sum = 0;
        for (int m : matchsticks) {
            sum += m;
        }
        if (sum % 4 != 0) return false;
        possibleLen = sum / 4;
        return backtrack(matchsticks, 0, sides);
    }
    
    bool backtrack(vector<int>& matchsticks, int index, vector<int>& sides) {
        if (index >= matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        for (int i = 0; i < 4; i++) {
            if ((i != 0 && sides[i] == sides[i - 1]) || sides[i] + matchsticks[index] > possibleLen) continue;
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, index + 1, sides)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        return false;
    }
};

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int m : matchsticks) {
            sum += m;
        }
        if (sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;
        return dfs(matchsticks, target, 0, 0, 4);
    }
    
    bool dfs(vector<int>& matchsticks, int target, int curr, int start, int k) {
        if (k == 1) return true;
        if (curr > target) return false;
        if (curr == target) {
            return dfs(matchsticks, target, 0, 0, k - 1);
        }
        for (int i = start; i < matchsticks.size(); i++) {
            if (matchsticks[i] > 0) {
                int tmp = matchsticks[i];
                matchsticks[i] = 0;
                if (dfs(matchsticks, target, curr + tmp, i + 1, k)) {
                    return true;
                }
                matchsticks[i] = tmp;
            }                        
        }
        return false;        
    }
};