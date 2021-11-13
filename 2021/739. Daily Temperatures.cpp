class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tStack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!tStack.empty() && temperatures[i] > temperatures[tStack.top()]) {
                res[tStack.top()] = i - tStack.top();
                tStack.pop();
            }
            tStack.push(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tStack;        
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!tStack.empty() && temperatures[i] > temperatures[tStack.top()]) {
                res[tStack.top()] = i - tStack.top();
                tStack.pop();
            }
            tStack.push(i);
        }        
        return res;
    }
};