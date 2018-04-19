class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        else if(s.length() == 1)
            return 1;
        int res[s.length()];
        string tmp;        
        res[0] = 1;        
        for (int  i = 1; i < s.length(); i++){                               
            if (s[i] == '0'){
                if (s[i - 1] >= '3' || s[i - 1] <='0')
                    return 0;
                else
                    res[i] = i > 1 ? res[i - 2] : 1;
            }
            else{
                tmp = s.substr(i-1, 2);
                res[i] = (tmp >= "10" && tmp <= "26") ? ( i > 1 ?  res[i-1] + res[i - 2] : res[i-1] + 1) : res[i-1];               
            }            
        }
        return res[s.length() - 1];
    }
};