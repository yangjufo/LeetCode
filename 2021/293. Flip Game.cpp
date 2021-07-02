class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;    
        for (int i = 1; i < currentState.size(); i++) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                res.push_back(currentState.substr(0, i - 1) + "--" + currentState.substr(i + 1));
            }
        }            
        return res;
    }
};