class Solution {
public:
    int maxGood = 0;
    int maximumGood(vector<vector<int>>& statements) {
        // 0 for bad, 1 for good, 2 for unknown
        vector<int> persons(statements.size(), 2);
        backtrack(statements, persons, 0);
        return maxGood;
    }

    void backtrackGood(vector<vector<int>>& statements, vector<int> persons, int index) {
        int j = 0;
        for (; j < statements[index].size(); j++) {
            if (statements[index][j] == 2) {
                continue;
            }
            if (statements[index][j] != persons[j] && persons[j] != 2) {
                break;
            }
            persons[j] = statements[index][j];
        }
        if (j >= statements[index].size()) {
            backtrack(statements, persons, index + 1);
        }
    }

    void backtrack(vector<vector<int>>& statements, vector<int> persons, int index) {
        if (index >= persons.size()) {
            int count = 0;
            for (int p : persons) {
                if (p == 1 || p == 2) {
                    count++;
                }
            }
            maxGood = max(maxGood, count);
            return;
        }
        if (persons[index] == 1) {
            backtrackGood(statements, persons, index);
        }
        else if (persons[index] == 0) {
            backtrack(statements, persons, index + 1);
        }
        else {
            persons[index] = 1;
            backtrackGood(statements, persons, index);
            persons[index] = 0;
            backtrack(statements, persons, index + 1);
        }
    }
};