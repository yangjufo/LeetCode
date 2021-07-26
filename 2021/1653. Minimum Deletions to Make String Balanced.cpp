class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> preB(s.length(), 0), postA(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            preB[i] = (i == 0) ? 0 : preB[i - 1];
            if (s[i] == 'b') {
                preB[i]++;
            }            
        }
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            postA[i] = (i + 1 == s.length()) ? 0 : postA[i + 1];
            if (s[i] == 'a') {
                postA[i]++;
            }
        }
        int minCount = s.length();
        for (int i = 0; i < s.length(); i++) {            
            minCount = min(minCount, min(postA[i] + (i == 0 ? 0 : preB[i - 1]), preB[i] + (i + 1 == s.length() ? 0 : postA[i + 1])));
        }
        return minCount;
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), bCount = 0, prev = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                curr = min(prev + 1, bCount);                
            } else {
                curr = prev;
                bCount++;
            }   
            prev = curr;
        }
        return prev;
    }
};