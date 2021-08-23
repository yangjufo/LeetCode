class Solution {
public:
    string solveEquation(string equation) {
        int leftX = 0, rightX = 0, leftSum = 0, rightSum = 0, sign = 1, i = 0;
        bool left = true;
        while (i < equation.length()) {
            if (equation[i] == '=') {
                left = false;
                sign = 1;
            } else if (equation[i] == '+' || equation[i] == '-') {
                sign = equation[i] == '-' ? -1 : 1;                
            } else if (equation[i] == 'x') {
                if (left) {
                    leftX += sign;
                } else {
                    rightX += sign;
                }
            } else if (isdigit(equation[i])) {
                int start = i;
                while (isdigit(equation[i])) {
                    i++;
                }                
                if (i < equation.length() && equation[i] == 'x') {
                    if (left) {
                        leftX += sign * stoi(equation.substr(start, i - start));
                    } else {
                        rightX += sign * stoi(equation.substr(start, i - start));
                    }
                } else {
                    if (left) {
                        leftSum += sign * stoi(equation.substr(start, i - start));
                    } else {
                        rightSum += sign * stoi(equation.substr(start, i - start));
                    }
                    i--;
                }                         
            }
            i++;
        }
        if (leftX == rightX) {
            return leftSum == rightSum ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string((leftSum - rightSum) / (rightX - leftX));
    }
};