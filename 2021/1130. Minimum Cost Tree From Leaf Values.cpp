class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
        
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> stack;
        stack.push(INT_MAX);
        for (int a : arr) {
            while (stack.top() <= a) {
                int mid = stack.top();
                stack.pop();
                res += mid * min(stack.top(), a);
            }
            stack.push(a);
        }
        if (stack.size() > 2) {
            int num1 = stack.top();
            stack.pop();
            int num2;
            while (stack.size() > 1) {
                num2 = stack.top();
                stack.pop();
                res += num1 * num2;
                num1 = num2;
            }
        }
        return res;
    }
};