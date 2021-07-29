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

class Solution {
public:    
    vector<int> diffWaysToCompute(string expression) {        
        return compute(expression, 0, (int)expression.size() - 1);
    }
    
    vector<int> compute(string& expression, int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftRes = compute(expression, left, i - 1);
                vector<int> rightRes = compute(expression, i + 1, right);
                for (int l : leftRes) {
                    for (int r : rightRes) {
                        switch(expression[i]) {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;                                                                
                        }                        
                    }
                }
            }            
        }
        if (res.empty()) {
            res.push_back(stoi(expression.substr(left, right - left + 1)));
        }
        return res;
    }
};


class Solution {
public:    
    vector<vector<vector<int>>> mem;
    vector<int> diffWaysToCompute(string expression) {
        mem.resize(20, vector<vector<int>>(20));
        return compute(expression, 0, (int)expression.size() - 1);
    }
    
    vector<int> compute(string& expression, int left, int right) {
        if (!mem[left][right].empty()) {
            return mem[left][right];
        }
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftRes = compute(expression, left, i - 1);
                vector<int> rightRes = compute(expression, i + 1, right);
                for (int l : leftRes) {
                    for (int r : rightRes) {
                        switch(expression[i]) {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;                                                                
                        }                        
                    }
                }
            }            
        }
        if (res.empty()) {
            res.push_back(stoi(expression.substr(left, right - left + 1)));
        }
        mem[left][right] = res;
        return res;
    }
};