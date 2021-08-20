class Solution {
public:
    string fractionAddition(string expression) {
        vector<pair<int, int>> nums;
        int start = 0, end = 0, numerator = 0, sign = 1;
        expression += "+";
        while (end < expression.length()) {
            if (expression[end] == '/') {                
                numerator = sign * stoi(expression.substr(start, end - start));
                start = end + 1;                
            } else if (expression[end] == '+' || expression[end] == '-') {
                sign = expression[end] == '+' ? 1 : -1;
                if (end != 0 && isdigit(expression[end - 1])) {                    
                    nums.push_back({numerator, stoi(expression.substr(start, end - start))});
                }
                start = end + 1;                
            }
            end++;
        }
        int base = 1;
        for (auto n : nums) {
            base *= n.second / gcd(base, n.second);
        }        
        int sum = 0;
        for (auto n : nums) {
            sum += base / n.second * n.first;
        }        
        int common = gcd(base, abs(sum));
        sum /= common;
        base /= common;
        return to_string(sum) + "/" + to_string(base);
    }
};