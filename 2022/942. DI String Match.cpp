class Solution {
public:
    vector<int> diStringMatch(string s) {
        int maxNum = s.length();
        int minNum = 0;
        vector<int> res;
        for (char c : s) {
            if (c == 'I') {
                res.push_back(minNum);
                minNum++;
            } else {
                res.push_back(maxNum);
                maxNum--;
            }
        }
        res.push_back(minNum);
        return res;
    }
};