class Solution {
public:
    string findContestMatch(int n) {
        vector<string> pairs;
        
        for (int i = 1; i <= n; i++) {
            pairs.push_back(to_string(i));
        }
        while (pairs.size() > 1) {
            vector<string> next;
            for (int i = 0; i * 2 < pairs.size(); i++) {
                next.push_back("(" + pairs[i] + "," + pairs[(int)pairs.size() - 1 - i] + ")");
            }
            pairs = next;
        }
        return pairs[0];
    }
};