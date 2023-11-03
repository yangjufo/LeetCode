class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 1;
        vector<string> ops;
        for (int t : target) {
            while (t > i) {
                ops.push_back("Push");
                ops.push_back("Pop");
                i++;
            }
            ops.push_back("Push");
            i++;
        }
        return ops;
    }
};