class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToCompute(expression, 0, expression.length() - 1);
    }
    
    vector<int> diffWaysToCompute(string& expression, int start, int end) {
        vector<int> res;
        for (int i = start; i <= end; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression, start, i - 1);
                vector<int> right = diffWaysToCompute(expression, i + 1, end);
                for (int l : left) {
                    for (int r : right) {                        
                        if (expression[i] == '+') {
                            res.push_back(l + r);
                        }
                        if (expression[i] == '-') {
                            res.push_back(l - r);
                        }
                        if (expression[i] == '*') {
                            res.push_back(l * r);
                        }
                    }
                }
            }            
        }
        if (res.empty()) {
            res.push_back(stoi(expression.substr(start, end + 1)));
        }
        return res;
    }
};