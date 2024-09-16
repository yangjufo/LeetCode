class Solution {
public:
    char genes[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> steps;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        return dfs(steps, startGene, endGene, bankSet, 0);
    }

    int dfs(unordered_map<string, int>& steps, string& startGene,
            string& endGene, unordered_set<string>& bank, int currStep) {
        for (int i = 0; i < 8; i++) {
            char original = startGene[i];
            for (int j = 0; j < 4; j++) {
                if (genes[j] == original) {
                    continue;
                }
                startGene[i] = genes[j];
                if (bank.find(startGene) == bank.end() ||
                    (steps.find(startGene) != steps.end() &&
                     steps[startGene] <= currStep + 1)) {
                    continue;
                }
                if (startGene == endGene) {
                    return currStep + 1;
                }
                steps[startGene] = currStep + 1;
                int step = dfs(steps, startGene, endGene, bank, currStep + 1);
                if (step > 0) {
                    return step;
                }
            }
            startGene[i] = original;
        }
        return -1;
    }
};