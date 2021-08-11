class Solution {
public:
    vector<int> findPermutation(string s) {        
        int n = s.length() + 1, curr = 1;
        vector<int> res(n, 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                res[i] = curr;
                curr++;
                for (int j = i - 1; j >= 0 && s[j] == 'D'; j--) {
                    res[j] = curr;
                    curr++;
                }
            }
        }                
        for (int i = n - 1; i >= 0 && curr <= n; i--) {
            res[i] = curr;
            curr++;
        }
        return res;        
    }
};

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length() + 1;
        vector<int> res(n, 0);
        stack<int> stack;
        int j = 0;
        for (int i = 1; i < s.length() + 1; i++) {            
            stack.push(i);
            if (s[i - 1] == 'I') {
                while (!stack.empty()) {                    
                    res[j] = stack.top();
                    stack.pop();
                    j++;
                }                
            }
        }
        stack.push(n);
        while (!stack.empty()) {
            res[j] = stack.top();
            stack.pop();
            j++;
        }
        return res;
    }
};