class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for (int i = 2; i <= n; i++) {
            string next = "";
            int count = 1;
            for (int j = 1; j < curr.length(); j++) {
                if (curr[j] == curr[j - 1]) {
                    count++;
                } else {
                    next += to_string(count) + curr[j - 1];
                    count = 1;
                }
            }
            next += to_string(count) + curr.back();
            curr = next;
        }
        return curr;
    }
};