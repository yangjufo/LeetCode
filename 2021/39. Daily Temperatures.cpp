class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> tStack;
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!tStack.empty() && T[i] > tStack.top().first) {
                res[tStack.top().second] = i - tStack.top().second;
                tStack.pop();
            }
            tStack.push({T[i], i});
        }
        return res;
    }
};