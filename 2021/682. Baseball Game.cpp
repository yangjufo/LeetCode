class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (string& c : ops) {
            if (c == "C") {
                scores.pop_back();
            } else if (c == "D") {
                scores.push_back(2 * scores.back());
            } else if (c == "+") {
                scores.push_back(scores[(int)scores.size() - 2] + scores.back());
            } else {
                scores.push_back(stoi(c));
            }
        }
        int sum = 0;
        for (int s : scores) {
            sum += s;
        }
        return sum;
    }
};