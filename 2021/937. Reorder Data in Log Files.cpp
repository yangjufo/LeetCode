class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans(logs.size(), "");
        int start = 0;
        int end = logs.size() - 1;
        for (int i = logs.size() - 1; i >= 0; i--) {
            if (isDigitLog(logs[i])) {
                ans[end] = logs[i];
                end--;
            } else {
                ans[start] = logs[i];
                start++;
            }
        }
        sort(ans.begin(), ans.begin() + start, [](string& left, string& right) {            
            bool ans = false;
            int i = 0, j = 0;
            while (left[i] != ' ') i++;
            while (right[j] != ' ') j++;                        
            while (i < left.length() && j < right.length()) {
                if (left[i] != right[j])  {
                    ans = left[i] < right[j];
                    break;
                }
                i++;
                j++;
            }
            if (i == left.length() || j == right.length())
                ans = left.length() < right.length();            
            return ans;
        });
        return ans;
    }
    
    bool isDigitLog(string& log) {
        int i = 0;
        while (log[i] != ' ') {
            i++;
        }
        return log[i + 1] >= '0' && log[i + 1] <= '9';
    }
};