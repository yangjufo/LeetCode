class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> moves;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                moves.push(i);
            }
        }
        while (!moves.empty()) {
            unordered_map<int, int> next;
            while (!moves.empty()) {
                int index = moves.front();
                moves.pop();
                if (dominoes[index] == 'L' && index > 0 && dominoes[index - 1] == '.') {
                    next[index - 1] += -1;
                } else if (dominoes[index] == 'R' && index + 1 < dominoes.size() && dominoes[index + 1] == '.') {
                    next[index + 1] += 1;
                }
            }
            for (auto& iter : next) {
                if (iter.second != 0) {
                    dominoes[iter.first] = (iter.second > 0) ? 'R' : 'L';
                    moves.push(iter.first);
                }
            }
        }
        return dominoes;
    }
};