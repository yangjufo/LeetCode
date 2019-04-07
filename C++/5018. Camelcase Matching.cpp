class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string q : queries) {
            int i, j;
            i = j = 0;
            while (i < q.length() && j < pattern.length()) {
                while (i < q.length() && q[i] != pattern[j] && q[i] <= 'z' && q[i] >= 'a')
                    i++;
                if (i < q.length() && q[i] != pattern[j])
                    break;
                if (i < q.length()) {
                    i++;
                    j++;
                }
            }                                                                        
            if(j == pattern.length() && i != q.length()) {
                while (i < q.length()) {
                    if (q[i] <= 'Z' && q[i] >= 'A')                        
                        break;                    
                    i++;
                }                
            }
            if (j == pattern.length() && i == q.length())
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};