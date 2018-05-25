class Solution {
public:
    string convert(string s, int numRows) {
        string tmp[numRows];
        int n = s.length();
        int i = 0;
        string res;
        while(i < n){
            for (int j = 0; j < numRows && i < n; j++){
                tmp[j] += s[i];
                i++;
            }
            
            for (int j = numRows - 2; j > 0 && i < n; j--){
                tmp[j] += s[i];
                i++;
            }                        
        }
        
        for (int j = 0; j < numRows; j++)
            res += tmp[j];
        return res;
    }
};