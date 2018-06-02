class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int res = 0;
        int new_num;        
        int flag = 0;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++){
            if (str[i] == ' ' && flag == 0)
                continue;
            else if (str[i] >= '0' && str[i] <= '9'){                
                if (flag == 0)
                    flag = 1;
                new_num = str[i] - '0';
                if (flag && (INT_MIN + new_num) * 1.0 / 10 > res)
                    return INT_MIN;
                else if ((INT_MAX - new_num) * 1.0 / 10 < res)
                    return INT_MAX;     
                if (flag == 1)
                    res = res * 10 + new_num;                
                else
                    res = res * 10 - new_num;
            }        
            else if (str[i] == '+' && flag == 0)
                flag = 1;
            else if (str[i] == '-' && flag == 0)
                flag = -1;
            else
                return res;
        }
        return res;
    }
};