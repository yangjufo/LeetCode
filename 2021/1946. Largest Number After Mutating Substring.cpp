class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {        
        int i = 0;
        while (i < num.length() && change[num[i] - '0'] <= num[i] - '0') {            
            i++;
        }
        string res = num.substr(0, i);
        while (i < num.length() && change[num[i] - '0'] >= num[i] - '0') {
            res += to_string(change[num[i] - '0']);
            i++;
        }        
        return res + num.substr(i);
    }
};